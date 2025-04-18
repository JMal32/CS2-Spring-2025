#include "hashTable.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<int> generateUniqueRandomNumbers(int count, int max) {
  vector<int> numbers;
  srand(time(0));

  while (numbers.size() < count) {
    int num = rand() % max;
    if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {
      numbers.push_back(num);
    }
  }
  return numbers;
}

void testSearches(int size, ofstream &csvFile) {
  // Generate master list of unique numbers
  vector<int> masterList = generateUniqueRandomNumbers(size + 1000, size * 2);

  // Get test lists
  vector<int> testList(masterList.begin(), masterList.begin() + size);
  vector<int> searchPresent = generateUniqueRandomNumbers(1000, size);
  vector<int> searchNotPresent(masterList.begin() + size,
                               masterList.begin() + size + 1000);

  // Test HashTable with 50% load factor
  HashTable<int> ht50;
  ht50.quickLoad(testList, 0.5);

  // Time present items
  chrono::high_resolution_clock::time_point start =
      chrono::high_resolution_clock::now();
  for (int num : searchPresent) {
    ht50.get(num);
  }
  chrono::high_resolution_clock::time_point end =
      chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;
  csvFile << size << "," << fixed << setprecision(9) << elapsed.count() / 1000.0
          << ",";

  // Time non-present items
  start = chrono::high_resolution_clock::now();
  for (int num : searchNotPresent) {
    ht50.get(num);
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  csvFile << elapsed.count() / 1000.0 << ",";

  // Test HashTable with 95% load factor
  HashTable<int> ht95;
  ht95.quickLoad(testList, 0.95);

  // Time present items
  start = chrono::high_resolution_clock::now();
  for (int num : searchPresent) {
    ht95.get(num);
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  csvFile << elapsed.count() / 1000.0 << ",";

  // Time non-present items
  start = chrono::high_resolution_clock::now();
  for (int num : searchNotPresent) {
    ht95.get(num);
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  csvFile << elapsed.count() / 1000.0 << ",";

  // Test sequential search
  // Time present items
  start = chrono::high_resolution_clock::now();
  for (int num : searchPresent) {
    find(testList.begin(), testList.end(), num) != testList.end();
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  csvFile << elapsed.count() / 1000.0 << ",";

  // Time non-present items
  start = chrono::high_resolution_clock::now();
  for (int num : searchNotPresent) {
    find(testList.begin(), testList.end(), num) != testList.end();
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  csvFile << elapsed.count() / 1000.0 << ",";

  // Test binary search
  sort(testList.begin(), testList.end());

  // Time present items
  start = chrono::high_resolution_clock::now();
  for (int num : searchPresent) {
    binary_search(testList.begin(), testList.end(), num);
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  csvFile << elapsed.count() / 1000.0 << ",";

  // Time non-present items
  start = chrono::high_resolution_clock::now();
  for (int num : searchNotPresent) {
    binary_search(testList.begin(), testList.end(), num);
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  csvFile << elapsed.count() / 1000.0 << endl;
}

int main() {
  ofstream csvFile("search_timing.csv");
  csvFile << "Size,HT50_Present,HT50_NotPresent,HT95_Present,HT95_NotPresent,"
             "Seq_Present,Seq_NotPresent,Bin_Present,Bin_NotPresent"
          << endl;

  cout << "Testing search algorithms..." << endl;

  for (int size = 100000; size <= 1000000; size += 100000) {
    testSearches(size, csvFile);
    cout << "Completed size " << size << endl;
  }

  csvFile.close();
  cout << "Results saved to search_timing.csv" << endl;

  return 0;
}
