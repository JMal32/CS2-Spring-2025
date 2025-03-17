#include "queueClass.h" // Include queue class
#include <cmath>        // For pow()
#include <cstdlib>      // For rand() and srand()
#include <ctime>        // For time() and timing
#include <fstream>      // For CSV file output
#include <iomanip>      // For formatting output
#include <iostream>
#include <vector>

// RadixSort function implementation
std::vector<unsigned long long> RadixSort(int sz) {
  // Create main bin queue
  QueueClass<unsigned long long> mainBin(sz);

  // Store original order for comparison
  std::vector<unsigned long long> original;

  // Fill main bin with random 9-digit integers
  for (int i = 0; i < sz; i++) {
    unsigned long long random_number = 100000000 + rand() % 900000000;
    mainBin.push(random_number);
    original.push_back(random_number);
  }

  // Print original list if size is small
  if (sz <= 10) {
    std::cout << "Original list: " << std::endl;
    for (unsigned long long num : original) {
      std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
  }

  // Create 10 digit bins (one for each possible digit 0-9)
  QueueClass<unsigned long long> digitBins[10] = {
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz)};

  // For each digit position (ones, tens, hundreds, etc.)
  for (int position = 0; position < 9; position++) {
    // Dequeue each number from the main bin and enqueue into appropriate digit
    // bin
    while (!mainBin.empty()) {
      unsigned long long num = mainBin.pop();
      int digit =
          (num / static_cast<unsigned long long>(pow(10, position))) % 10;
      digitBins[digit].push(num);
    }

    // Dequeue from digit bins in order and enqueue back into the main bin
    for (int d = 0; d < 10; d++) {
      while (!digitBins[d].empty()) {
        mainBin.push(digitBins[d].pop());
      }
    }
  }

  // Dequeue each number from the main bin into a "results" vector
  std::vector<unsigned long long> results;
  while (!mainBin.empty()) {
    results.push_back(mainBin.pop());
  }
  return results;
}

int main() {
  // Seed random number generator
  srand(static_cast<unsigned int>(time(nullptr)));

  // Test with size=10 sample
  std::cout << "Testing RadixSort with 10 elements:" << std::endl;
  std::vector<unsigned long long> sorted = RadixSort(10);

  std::cout << "Sorted list: " << std::endl;
  for (unsigned long long num : sorted) {
    std::cout << num << " ";
  }
  std::cout << std::endl << std::endl;

  // Open CSV file for timing data
  std::ofstream csvFile("radix_sort_timing.csv");
  csvFile << "Size,Time(seconds)" << std::endl;

  std::cout << "Generating timing data..." << std::endl;

  // Time tests for sizes from 1000 to 10000
  for (int size = 1000; size <= 10000; size += 1000) {
    clock_t start = clock();
    RadixSort(size);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    csvFile << size << "," << std::fixed << std::setprecision(5) << elapsed
            << std::endl;
    std::cout << "Completed size " << size << std::endl;
  }

  csvFile.close();
  std::cout << "Timing data saved to radix_sort_timing.csv" << std::endl;

  return 0;
}
