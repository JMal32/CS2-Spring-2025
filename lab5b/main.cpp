#include <iostream>
#include <vector>
#include <fstream>
#include "hashTable.h"
#include "search.h"

// Function to run timing tests for a specific size
void runTimingTests(int size, std::ofstream& outFile) {
    // Generate master list of 1,001,000 integers
    std::vector<int> TOTLIST = generateUniqueRandomNumbers(1001000, 0, 10000000);
    
    // Create INS and srchNotINS lists
    std::vector<int> INS(TOTLIST.begin(), TOTLIST.begin() + size);
    std::vector<int> srchNotINS(TOTLIST.begin() + 1000000, TOTLIST.end());
    
    // Generate search lists
    std::vector<int> srchINS = generateUniqueRandomNumbers(1000, 0, size - 1);
    
    // Create hash tables with different load factors
    HashTable<int> ht50, ht95;
    ht50.quickLoad(INS, 0.50);
    ht95.quickLoad(INS, 0.95);
    
    // Sort INS for binary search
    std::vector<int> sortedINS = INS;
    std::sort(sortedINS.begin(), sortedINS.end());
    
    // Timing variables
    double totalTime = 0.0;
    
    // Hash Table 50% load factor timing (present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime([&ht50](int x) { return ht50.get(x); }, srchINS[i]);
    }
    outFile << size << ",HT50_Present," << totalTime / 1000.0 << std::endl;
    
    // Hash Table 95% load factor timing (present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime([&ht95](int x) { return ht95.get(x); }, srchINS[i]);
    }
    outFile << size << ",HT95_Present," << totalTime / 1000.0 << std::endl;
    
    // Hash Table 50% load factor timing (non-present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime([&ht50](int x) { return ht50.get(x); }, srchNotINS[i]);
    }
    outFile << size << ",HT50_NonPresent," << totalTime / 1000.0 << std::endl;
    
    // Hash Table 95% load factor timing (non-present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime([&ht95](int x) { return ht95.get(x); }, srchNotINS[i]);
    }
    outFile << size << ",HT95_NonPresent," << totalTime / 1000.0 << std::endl;
    
    // Sequential Search timing (present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime(sequentialSearch<int>, INS, srchINS[i]);
    }
    outFile << size << ",Seq_Present," << totalTime / 1000.0 << std::endl;
    
    // Sequential Search timing (non-present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime(sequentialSearch<int>, INS, srchNotINS[i]);
    }
    outFile << size << ",Seq_NonPresent," << totalTime / 1000.0 << std::endl;
    
    // Binary Search timing (present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime(binarySearch<int>, sortedINS, srchINS[i]);
    }
    outFile << size << ",Bin_Present," << totalTime / 1000.0 << std::endl;
    
    // Binary Search timing (non-present items)
    totalTime = 0.0;
    for (int i = 0; i < 1000; ++i) {
        totalTime += measureTime(binarySearch<int>, sortedINS, srchNotINS[i]);
    }
    outFile << size << ",Bin_NonPresent," << totalTime / 1000.0 << std::endl;
}

int main() {
    std::ofstream outFile("timing_results.csv");
    outFile << "Size,Algorithm,AvgTime(ms)" << std::endl;
    
    // Run tests for sizes from 100,000 to 1,000,000 in steps of 100,000
    for (int size = 100000; size <= 1000000; size += 100000) {
        std::cout << "Testing size: " << size << std::endl;
        runTimingTests(size, outFile);
    }
    
    outFile.close();
    std::cout << "Timing results have been written to timing_results.csv" << std::endl;
    
    return 0;
} 