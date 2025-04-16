#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<unsigned long long> &alist) {
  for (int sznum = alist.size() - 1; sznum > 0; sznum--) {
    for (int i = 0; i < sznum; i++) {
      if (alist[i] > alist[i + 1]) {
        // swapping elements here
        int temp = alist[i];
        alist[i] = alist[i + 1];
        alist[i + 1] = temp;
      }
    }
  }
}

unsigned long long getInt(int numDigits = 10) {
  unsigned long long num = 0;

  num = rand() % 9 + 1;
  for (int i = 0; i < numDigits - 1; i++) {
    num = num * 10 + rand() % 10;
  }
  return num;
}

void getUniqueNums(int sz, vector<unsigned long long> &v) {

  while (v.size() < sz) {
    unsigned long long num = getInt(9);
    if (find(v.begin(), v.end(), num) == v.end()) {
      v.push_back(num);
    }
  }
}
int main() {
  ofstream csvFile("bin_timing.csv");
  csvFile << "Size,SearchType,Time(milliseconds)" << endl;

  cout << "Generating Timing Data..." << endl;

  vector<int> testSize = {1000,  2000,   5000,   10000,  20000,
                          50000, 100000, 200000, 500000, 1000000};

  for (int size : testSize) {
    vector<unsigned long long> originalVec;
    getUniqueNums(size, originalVec);
    cout << size << " unique numbers generated!" << endl;

    vector<unsigned long long> vec =
        originalVec; // made a copy of the original list to use for timing
    auto start1 = chrono::high_resolution_clock::now();
    bubbleSort(vec);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> total = end1 - start1;

    csvFile << size << "Time:" << fixed << setprecision(4) << total.count()
            << endl;

    cout << "The list has been sorted!" << endl;
  }
  csvFile.close();

  return 0;
}
