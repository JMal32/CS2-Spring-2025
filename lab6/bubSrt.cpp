#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<unsigned long long> &alist) {
  for (int sznum = alist.size() - 1; sznum > 0; sznum--) {
    for (int i = 0; i < sznum; i++) {
      if (alist[i] > alist[i + 1]) {
        // swapping elements here
        unsigned long long temp = alist[i];
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
  ofstream csvFile("bubble_timing.csv");
  csvFile << "Size,Algorithm,Time(milliseconds)" << endl;

  cout << "Generating Timing Data..." << endl;

  vector<int> testSize = {10000, 20000, 30000, 40000, 50000,
                          60000, 70000, 80000, 90000, 100000};

  for (int size : testSize) {
    vector<unsigned long long> originalVec;
    getUniqueNums(size, originalVec);
    cout << size << " unique numbers generated!" << endl;

    vector<unsigned long long> vec =
        originalVec; // made a copy of the original list to use for timing
    chrono::high_resolution_clock::time_point start =
        chrono::high_resolution_clock::now();
    bubbleSort(vec);
    chrono::high_resolution_clock::time_point end =
        chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time_span = end - start;

    csvFile << size << ",BubbleSort," << fixed << setprecision(4)
            << time_span.count() << endl;

    cout << "The list has been sorted!" << endl;
  }
  csvFile.close();

  return 0;
}
