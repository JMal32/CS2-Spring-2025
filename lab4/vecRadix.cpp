#include "vecQueue.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<unsigned long long> RadixSort(int sz) {
  QueueClass<unsigned long long> mainBin(sz);

  vector<unsigned long long> original;

  for (int i = 0; i < sz; i++) {
    unsigned long long random_number = 100000000 + rand() % 900000000;
    mainBin.push(random_number);
    original.push_back(random_number);
  }

  if (sz <= 10) {
    cout << "Original list: " << endl;
    for (unsigned long long num : original) {
      cout << num << " ";
    }
    cout << endl << endl;
  }

  QueueClass<unsigned long long> digitBins[10] = {
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz),
      QueueClass<unsigned long long>(sz), QueueClass<unsigned long long>(sz)};

  for (int position = 0; position < 9; position++) {
    while (!mainBin.empty()) {
      unsigned long long num = mainBin.pop();
      int digit =
          (num / static_cast<unsigned long long>(pow(10, position))) % 10;
      digitBins[digit].push(num);
    }

    for (int d = 0; d < 10; d++) {
      while (!digitBins[d].empty()) {
        mainBin.push(digitBins[d].pop());
      }
    }
  }

  vector<unsigned long long> results;
  while (!mainBin.empty()) {
    results.push_back(mainBin.pop());
  }
  return results;
}

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  cout << "Testing RadixSort with 10 elements:" << endl;
  vector<unsigned long long> sorted = RadixSort(10);

  cout << "Sorted list: " << endl;
  for (unsigned long long num : sorted) {
    cout << num << " ";
  }
  cout << endl << endl;

  ofstream csvFile("radix_sort_timing.csv");
  csvFile << "Size,Time(seconds)" << endl;

  cout << "Generating timing data..." << endl;

  for (int size = 1000; size <= 10000; size += 1000) {
    auto start = chrono::high_resolution_clock::now();
    RadixSort(size);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    csvFile << size << "," << fixed << setprecision(5) << elapsed.count() << endl;
    cout << "Completed size " << size << endl;
  }

  csvFile.close();
  cout << "Timing data saved to radix_sort_timing.csv" << endl;

  return 0;
}
