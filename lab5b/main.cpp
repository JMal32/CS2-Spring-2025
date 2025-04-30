#include "hashTable.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<int> generateUniqueRandomNumbers(int count, int max) {
  // just make a bunch of random numbers
  vector<int> numbers;
  srand(time(NULL));

  cout << "Making " << count << " random numbers..." << endl;

  while (numbers.size() < count) {
    int num = rand() % max;
    // check if we already have this number
    if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {
      numbers.push_back(num);

      // show a bit of progress so we know it's working
      if (numbers.size() % (count / 10) == 0 && numbers.size() > 0) {
        cout << "Got " << numbers.size() << " numbers so far" << endl;
      }
    }
  }
  cout << "Done making random numbers!" << endl;
  return numbers;
}

int main() {
  cout << "Let's test some search algorithms..." << endl;

  vector<int> masterList = generateUniqueRandomNumbers(1001000, 2000000);
  cout << "Got our master list." << endl;

  ofstream csvFile("search_timing.csv");
  csvFile << "Size,HT50_Present,HT50_NotPresent,HT95_Present,HT95_NotPresent,"
             "Seq_Present,Seq_NotPresent,Bin_Present,Bin_NotPresent"
          << endl;

  cout << "Now we'll test the search algorithms..." << endl;

  for (int size = 100000; size <= 1000000; size += 100000) {
    cout << "Testing size " << size << "..." << endl;

    // grab the data we need
    vector<int> testList(masterList.begin(), masterList.begin() + size);
    vector<int> searchPresent(masterList.begin() + size,
                              masterList.begin() + size + 1000);
    vector<int> searchNotPresent(masterList.begin() + size + 1000,
                                 masterList.begin() + size + 2000);

    csvFile << size << ",";

    // HT50 with values that are there
    cout << "  Testing HT with 50% load (present values)..." << endl;
    HashTable<int> ht50;
    ht50.quickLoad(testList, 0.5);

    auto start = chrono::high_resolution_clock::now();
    for (int num : searchPresent) {
      bool found = ht50.get(num);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    csvFile << fixed << setprecision(9) << elapsed.count() / 1000.0 << ",";

    // HT50 with values that aren't there
    cout << "  Testing HT with 50% load (absent values)..." << endl;
    start = chrono::high_resolution_clock::now();
    for (int num : searchNotPresent) {
      bool found = ht50.get(num);
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    csvFile << elapsed.count() / 1000.0 << ",";

    // HT95 with values that are there
    cout << "  Testing HT with 95% load (present values)..." << endl;
    HashTable<int> ht95;
    ht95.quickLoad(testList, 0.95);

    start = chrono::high_resolution_clock::now();
    for (int num : searchPresent) {
      bool found = ht95.get(num);
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    csvFile << elapsed.count() / 1000.0 << ",";

    // HT95 with values that aren't there
    cout << "  Testing HT with 95% load (absent values)..." << endl;
    start = chrono::high_resolution_clock::now();
    for (int num : searchNotPresent) {
      bool found = ht95.get(num);
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    csvFile << elapsed.count() / 1000.0 << ",";

    // regular search with values that are there
    cout << "  Testing regular search (present values)..." << endl;
    start = chrono::high_resolution_clock::now();
    for (int num : searchPresent) {
      bool found =
          find(testList.begin(), testList.end(), num) != testList.end();
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    csvFile << elapsed.count() / 1000.0 << ",";

    // regular search with values that aren't there
    cout << "  Testing regular search (absent values)..." << endl;
    start = chrono::high_resolution_clock::now();
    for (int num : searchNotPresent) {
      bool found =
          find(testList.begin(), testList.end(), num) != testList.end();
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    csvFile << elapsed.count() / 1000.0 << ",";

    // binary search with values that are there
    cout << "  Testing binary search (present values)..." << endl;
    vector<int> sortedList = testList;
    sort(sortedList.begin(), sortedList.end());

    start = chrono::high_resolution_clock::now();
    for (int num : searchPresent) {
      bool found = binary_search(sortedList.begin(), sortedList.end(), num);
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    csvFile << elapsed.count() / 1000.0 << ",";

    // binary search with values that aren't there
    cout << "  Testing binary search (absent values)..." << endl;
    start = chrono::high_resolution_clock::now();
    for (int num : searchNotPresent) {
      bool found = binary_search(sortedList.begin(), sortedList.end(), num);
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    csvFile << elapsed.count() / 1000.0 << endl;

    cout << "  Done with size " << size << endl;
  }

  csvFile.close();
  cout << "All done! Results are in search_timing.csv" << endl;

  return 0;
}
