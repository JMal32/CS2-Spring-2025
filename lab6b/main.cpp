#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Fraction.h"
using namespace std;

// Simple random number generator
int getRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Generate random fractions
vector<Fraction> generateRandomFractions(int size) {
    vector<Fraction> fractions;
    for (int i = 0; i < size; i++) {
        int num = getRandomNumber(1, 100);
        int den = getRandomNumber(1, 100);
        if (num > den) swap(num, den);
        fractions.push_back(Fraction(num, den));
    }
    return fractions;
}

// MergeSort functions
void merge(vector<Fraction>& arr, int left, int mid, int right) {
    vector<Fraction> L, R;
    L.insert(L.begin(), arr.begin() + left, arr.begin() + mid + 1);
    R.insert(R.begin(), arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSortHelper(vector<Fraction>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<Fraction>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// QuickSort functions
int partition(vector<Fraction>& arr, int low, int high) {
    Fraction pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<Fraction>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<Fraction>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

// Hungarian QuickSort functions
int hPartition(vector<Fraction>& arr, int low, int high) {
    Fraction pivot = arr[low];
    int i = low;
    int j = high;
    
    while (true) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i >= j) return j;
        
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void hQuickSortHelper(vector<Fraction>& arr, int low, int high) {
    if (low < high) {
        int pi = hPartition(arr, low, high);
        hQuickSortHelper(arr, low, pi);
        hQuickSortHelper(arr, pi + 1, high);
    }
}

void hQuickSort(vector<Fraction>& arr) {
    hQuickSortHelper(arr, 0, arr.size() - 1);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    
    const int NUM_TESTS = 5;
    const vector<int> SIZES = {100, 1000, 10000, 20000, 50000, 100000};
    vector<double> mergeTimes(SIZES.size(), 0.0);
    vector<double> quickTimes(SIZES.size(), 0.0);
    vector<double> hQuickTimes(SIZES.size(), 0.0);
    
    // Run tests for each size
    for (size_t i = 0; i < SIZES.size(); i++) {
        for (int test = 0; test < NUM_TESTS; test++) {
            vector<Fraction> fractions = generateRandomFractions(SIZES[i]);
            
            // Time merge sort
            vector<Fraction> mergeCopy = fractions;
            chrono::high_resolution_clock::time_point mergeStart = chrono::high_resolution_clock::now();
            mergeSort(mergeCopy);
            chrono::high_resolution_clock::time_point mergeEnd = chrono::high_resolution_clock::now();
            mergeTimes[i] += chrono::duration<double, milli>(mergeEnd - mergeStart).count();
            
            // Time quick sort
            vector<Fraction> quickCopy = fractions;
            chrono::high_resolution_clock::time_point quickStart = chrono::high_resolution_clock::now();
            quickSort(quickCopy);
            chrono::high_resolution_clock::time_point quickEnd = chrono::high_resolution_clock::now();
            quickTimes[i] += chrono::duration<double, milli>(quickEnd - quickStart).count();
            
            // Time Hungarian quick sort
            vector<Fraction> hQuickCopy = fractions;
            chrono::high_resolution_clock::time_point hQuickStart = chrono::high_resolution_clock::now();
            hQuickSort(hQuickCopy);
            chrono::high_resolution_clock::time_point hQuickEnd = chrono::high_resolution_clock::now();
            hQuickTimes[i] += chrono::duration<double, milli>(hQuickEnd - hQuickStart).count();
        }
        
        mergeTimes[i] /= NUM_TESTS;
        quickTimes[i] /= NUM_TESTS;
        hQuickTimes[i] /= NUM_TESTS;
        cout << "Done with size " << SIZES[i] << "\n";
    }
    
    // Print results
    cout << "\nTiming Results:\nSize\tMergeSort (ms)\tQuickSort (ms)\tHQuickSort (ms)\n----------------------------------------\n";
    for (size_t i = 0; i < SIZES.size(); i++) {
        cout << SIZES[i] << "\t" << fixed << setprecision(3) << mergeTimes[i] << "\t\t" << quickTimes[i] << "\t\t" << hQuickTimes[i] << "\n";
    }
    
    // Save to CSV
    ofstream csvFile("sorting_results.csv");
    if (csvFile.is_open()) {
        csvFile << "Size,MergeSort (ms),QuickSort (ms),HQuickSort (ms)\n";
        for (size_t i = 0; i < SIZES.size(); i++) {
            csvFile << SIZES[i] << "," << fixed << setprecision(3) << mergeTimes[i] << "," << quickTimes[i] << "," << hQuickTimes[i] << "\n";
        }
        csvFile.close();
        cout << "\nResults saved to sorting_results.csv\n";
    }
    
    return 0;
} 