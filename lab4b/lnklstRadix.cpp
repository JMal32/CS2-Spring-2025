#include "radLink.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// LinkedList RadixSort function
vector<unsigned long long>& LLRxSort(vector<unsigned long long>& vlist) {
    // Create main bin and enqueue all values
    LLQueue<unsigned long long> mainBin;
    for (unsigned long long num : vlist) {
        mainBin.push(num);
    }
    
    // Create 10 digit bins
    LLQueue<unsigned long long> digitBins[10];
    
    // Process each digit position (6 positions for 6-digit numbers)
    for (int position = 0; position < 6; position++) {
        // Distribute values to digit bins
        while (!mainBin.empty()) {
            unsigned long long num = mainBin.pop();
            int digit = (num / static_cast<unsigned long long>(pow(10, position))) % 10;
            digitBins[digit].push(num);
        }
        
        // Collect values back into main bin
        for (int d = 0; d < 10; d++) {
            while (!digitBins[d].empty()) {
                mainBin.push(digitBins[d].pop());
            }
        }
    }
    
    // Return sorted values back to original vector
    vlist.clear();
    while (!mainBin.empty()) {
        vlist.push_back(mainBin.pop());
    }
    return vlist;
}

// Vector-based RadixSort function (Lab 4 version)
vector<unsigned long long>& vectorRadixSort(vector<unsigned long long>& vlist) {
    vector<vector<unsigned long long>> digitBins(10);
    for (int position = 0; position < 6; position++) {
        for (unsigned long long num : vlist) {
            int digit = (num / static_cast<unsigned long long>(pow(10, position))) % 10;
            digitBins[digit].push_back(num);
        }
        vlist.clear();
        for (int d = 0; d < 10; d++) {
            for (unsigned long long num : digitBins[d]) {
                vlist.push_back(num);
            }
            digitBins[d].clear();
        }
    }
    return vlist;
}

// Generate vector of random numbers
vector<unsigned long long> generateRandomNumbers(int size) {
    vector<unsigned long long> numbers;
    for (int i = 0; i < size; i++) {
        unsigned long long num = 100000 + rand() % 900000;
        numbers.push_back(num);
    }
    return numbers;
}

int main() {
    /* Seed random number generator with current time - I can explain how this works
    in greater detail just in case you want an explanation to make sure I know what's happening and
    that I didn't just blindly copy it from a chatbot. */
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(static_cast<unsigned int>(seed));
    
    // This is where I demonstrate LinkedList2 as a Queue
    LinkedList2<unsigned long long> list;
    cout << "Original 10 random numbers:" << endl;
    
    vector<unsigned long long> numbers = generateRandomNumbers(10);
    for (unsigned long long num : numbers) {
        list.enqueue(num);
        cout << num << " ";
    }
    cout << endl;
    
    cout << "After dequeuing (should be same order):" << endl;
    while (!list.isEmpty()) {
        cout << list.dequeue() << " ";
    }
    cout << endl << endl;
    
    // This is where I demonstrate LLRxSort
    vector<unsigned long long> sort_numbers = generateRandomNumbers(10);
    
    cout << "Unsorted list:" << endl;
    for (unsigned long long num : sort_numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    LLRxSort(sort_numbers);
    
    cout << "Sorted list:" << endl;
    for (unsigned long long num : sort_numbers) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    // Compare both RadixSort implementations
    ofstream csvFile("radix_sort_timing.csv");
    csvFile << "Implementation,Size,Time(milliseconds)" << endl;
    
    cout << "Generating timing data..." << endl;
    
    // First run all LinkedList RadixSort timings
    for (int size = 100000; size <= 1000000; size += 100000) {
        vector<unsigned long long> ll_test_data = generateRandomNumbers(size);
        
        auto start = chrono::high_resolution_clock::now();
        LLRxSort(ll_test_data);
        auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double> elapsed = end - start;
        csvFile << "LinkedList," << size << "," << fixed << setprecision(2) << (elapsed.count() * 1000) << endl;
        cout << "LinkedList Size " << size << ": " << (elapsed.count() * 1000) << " milliseconds" << endl;
    }
    
    // Then run all Vector RadixSort timings
    for (int size = 100000; size <= 1000000; size += 100000) {
        vector<unsigned long long> vec_test_data = generateRandomNumbers(size);
        
        auto start = chrono::high_resolution_clock::now();
        vectorRadixSort(vec_test_data);
        auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double>elapsed = end - start;
        csvFile << "Vector," << size << "," << fixed << setprecision(2) << (elapsed.count() * 1000) << endl;
        cout << "Vector Size " << size << ": " << (elapsed.count() * 1000) << " milliseconds" << endl;
    }
    
    csvFile.close();
    cout << "Timing data saved to radix_sort_timing.csv" << endl;
    
    return 0;
}
