#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "HashTable.h"
using namespace std;

vector<int> generateUniqueRandom(int size) {
    vector<int> numbers;
    for (int i = 0; i < size; i++) {
        numbers.push_back(i);
    }
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(numbers[i], numbers[j]);
    }
    return numbers;
}

bool sequentialSearch(const vector<int>& arr, int target) {
    for (int num : arr) {
        if (num == target) return true;
    }
    return false;
}

bool binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    
    ofstream outFile("timing_results.csv");
    outFile << "Size,HT50_Present (ms),HT95_Present (ms),Seq_Present (ms),Bin_Present (ms),HT50_NotPresent (ms),HT95_NotPresent (ms),Seq_NotPresent (ms),Bin_NotPresent (ms)\n";
    
    vector<int> TOTLIST = generateUniqueRandom(1001000);
    vector<int> INS(TOTLIST.begin(), TOTLIST.begin() + 1000000);
    vector<int> NOTINS(TOTLIST.begin() + 1000000, TOTLIST.end());
    
    vector<int> sizes = {100000, 200000, 300000, 400000, 500000, 
                        600000, 700000, 800000, 900000, 1000000};
    
    cout << "Starting timing tests...\n";
    cout << "Size\tHT50\tHT95\tSeq\tBin\tHT50N\tHT95N\tSeqN\tBinN\n";
    cout << "----------------------------------------------------------------\n";
    
    for (int size : sizes) {
        cout << "Processing size " << size << "...\n";
        vector<int> currentINS(INS.begin(), INS.begin() + size);
        vector<int> currentNOTINS(NOTINS.begin(), NOTINS.begin() + 1000);
        
        // HashTable 50% load
        HashTable ht50;
        ht50.quickLoad(currentINS, 0.50);
        
        // HashTable 95% load
        HashTable ht95;
        ht95.quickLoad(currentINS, 0.95);
        
        // Timing variables for present items
        chrono::duration<double, milli> ht50Time(0);
        chrono::duration<double, milli> ht95Time(0);
        chrono::duration<double, milli> seqTime(0);
        chrono::duration<double, milli> binTime(0);
        
        // Timing variables for not present items
        chrono::duration<double, milli> ht50TimeNot(0);
        chrono::duration<double, milli> ht95TimeNot(0);
        chrono::duration<double, milli> seqTimeNot(0);
        chrono::duration<double, milli> binTimeNot(0);
        
        // Test present items
        for (int item : currentINS) {
            auto start = chrono::high_resolution_clock::now();
            ht50.get(item);
            auto end = chrono::high_resolution_clock::now();
            ht50Time += end - start;
            
            start = chrono::high_resolution_clock::now();
            ht95.get(item);
            end = chrono::high_resolution_clock::now();
            ht95Time += end - start;
            
            start = chrono::high_resolution_clock::now();
            sequentialSearch(currentINS, item);
            end = chrono::high_resolution_clock::now();
            seqTime += end - start;
            
            start = chrono::high_resolution_clock::now();
            binarySearch(currentINS, item);
            end = chrono::high_resolution_clock::now();
            binTime += end - start;
        }
        
        // Test not present items
        for (int item : currentNOTINS) {
            auto start = chrono::high_resolution_clock::now();
            ht50.get(item);
            auto end = chrono::high_resolution_clock::now();
            ht50TimeNot += end - start;
            
            start = chrono::high_resolution_clock::now();
            ht95.get(item);
            end = chrono::high_resolution_clock::now();
            ht95TimeNot += end - start;
            
            start = chrono::high_resolution_clock::now();
            sequentialSearch(currentINS, item);
            end = chrono::high_resolution_clock::now();
            seqTimeNot += end - start;
            
            start = chrono::high_resolution_clock::now();
            binarySearch(currentINS, item);
            end = chrono::high_resolution_clock::now();
            binTimeNot += end - start;
        }
        
        // Calculate averages
        double ht50Avg = ht50Time.count() / size;
        double ht95Avg = ht95Time.count() / size;
        double seqAvg = seqTime.count() / size;
        double binAvg = binTime.count() / size;
        double ht50NotAvg = ht50TimeNot.count() / 1000;
        double ht95NotAvg = ht95TimeNot.count() / 1000;
        double seqNotAvg = seqTimeNot.count() / 1000;
        double binNotAvg = binTimeNot.count() / 1000;
        
        // Print current results
        cout << size << "\t" << fixed << setprecision(3) 
             << ht50Avg << "\t" << ht95Avg << "\t" 
             << seqAvg << "\t" << binAvg << "\t"
             << ht50NotAvg << "\t" << ht95NotAvg << "\t"
             << seqNotAvg << "\t" << binNotAvg << "\n";
        
        // Write to CSV
        outFile << size << "," << fixed << setprecision(3)
                << ht50Avg << "," << ht95Avg << ","
                << seqAvg << "," << binAvg << ","
                << ht50NotAvg << "," << ht95NotAvg << ","
                << seqNotAvg << "," << binNotAvg << "\n";
    }
    
    outFile.close();
    cout << "\nResults saved to timing_results.csv\n";
    return 0;
} 