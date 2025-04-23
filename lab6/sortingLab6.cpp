#include "fraction.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/* Ater trying, and researching a few different ways to implement these
 * algorithms, I decided to define each one of them individually as a template.
 * This way I don't have to write each function
 * twice (1 for ints and 1 for fractions).*/
template <typename T> void bubbleSort(vector<T> &alist) {
  for (int sznum = alist.size() - 1; sznum > 0; sznum--) {
    for (int i = 0; i < sznum; i++) {
      if (alist[i] > alist[i + 1]) {
        T temp = alist[i];
        alist[i] = alist[i + 1];
        alist[i + 1] = temp;
      }
    }
  }
}

template <typename T> void insertionSort(vector<T> &alist) {
  for (int i = 1; i < alist.size(); i++) {
    T key = alist[i];
    int j = i - 1;

    while (j >= 0 && alist[j] > key) {
      alist[j + 1] = alist[j];
      j = j - 1;
    }
    alist[j + 1] = key;
  }
}

template <typename T> void selectionSort(vector<T> &alist) {
  for (int i = 0; i < alist.size() - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < alist.size(); j++) {
      if (alist[j] < alist[min_index]) {
        min_index = j;
      }
    }
    T temp = alist[i];
    alist[i] = alist[min_index];
    alist[min_index] = temp;
  }
}

template <typename T> void shellSort(vector<T> &alist) {
  for (int gap = alist.size() / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < alist.size(); i++) {
      T temp = alist[i];
      int j;
      for (j = i; j >= gap && alist[j - gap] > temp; j -= gap) {
        alist[j] = alist[j - gap];
      }
      alist[j] = temp;
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
  v.clear();
  while (v.size() < sz) {
    unsigned long long num = getInt(9);
    if (find(v.begin(), v.end(), num) == v.end()) {
      v.push_back(num);
    }
  }
}

void getUniqueFractions(int sz, vector<Fraction> &v) {
  v.clear();
  while (v.size() < sz) {
    int num = rand() % 1000 - 500;
    int den = rand() % 999 + 1;
    Fraction f(num, den);

    bool duplicate = false;
    for (const Fraction &existing : v) {
      if (f == existing) {
        duplicate = true;
        break;
      }
    }

    if (!duplicate) {
      v.push_back(f);
    }
  }
}

int main() {
  srand(time(NULL));
  ofstream csvFile("sorting_timing.csv");
  csvFile << "Algorithm,DataType,Size,Time(milliseconds)" << endl;

  cout << "Generating Timing Data..." << endl;

  vector<int> testSize = {10000, 20000, 30000, 40000, 50000,
                          60000, 70000, 80000, 90000, 100000};

  // BubbleSort algorithm
  for (int size : testSize) {
    // Generate the test data
    vector<unsigned long long> originalIntVec;
    vector<Fraction> originalFracVec;

    getUniqueNums(size, originalIntVec);
    getUniqueFractions(size, originalFracVec);
    cout << size << " unique elements generated!" << endl;

    // Test BubbleSort with integers
    vector<unsigned long long> intVecCopy = originalIntVec;
    chrono::high_resolution_clock::time_point start =
        chrono::high_resolution_clock::now();
    bubbleSort(intVecCopy);
    chrono::high_resolution_clock::time_point end =
        chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time_span = end - start;

    csvFile << "BubbleSort,Integer," << size << "," << fixed << setprecision(4)
            << time_span.count() << endl;
    cout << "BubbleSort (Integer, " << size << ") completed!" << endl;

    // Test BubbleSort with fractions
    vector<Fraction> fracVecCopy = originalFracVec;
    start = chrono::high_resolution_clock::now();
    bubbleSort(fracVecCopy);
    end = chrono::high_resolution_clock::now();
    time_span = end - start;

    csvFile << "BubbleSort,Fraction," << size << "," << fixed << setprecision(4)
            << time_span.count() << endl;
    cout << "BubbleSort (Fraction, " << size << ") completed!" << endl;
  }

  // InsertionSort algorithm
  for (int size : testSize) {
    // Generate the test data
    vector<unsigned long long> originalIntVec;
    vector<Fraction> originalFracVec;

    getUniqueNums(size, originalIntVec);
    getUniqueFractions(size, originalFracVec);

    // Test InsertionSort with integers
    vector<unsigned long long> intVecCopy = originalIntVec;
    chrono::high_resolution_clock::time_point start =
        chrono::high_resolution_clock::now();
    insertionSort(intVecCopy);
    chrono::high_resolution_clock::time_point end =
        chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time_span = end - start;

    csvFile << "InsertionSort,Integer," << size << "," << fixed
            << setprecision(4) << time_span.count() << endl;
    cout << "InsertionSort (Integer, " << size << ") completed!" << endl;

    // Test InsertionSort with fractions
    vector<Fraction> fracVecCopy = originalFracVec;
    start = chrono::high_resolution_clock::now();
    insertionSort(fracVecCopy);
    end = chrono::high_resolution_clock::now();
    time_span = end - start;

    csvFile << "InsertionSort,Fraction," << size << "," << fixed
            << setprecision(4) << time_span.count() << endl;
    cout << "InsertionSort (Fraction, " << size << ") completed!" << endl;
  }

  // SelectionSort algorithm
  for (int size : testSize) {
    // Generate the test data
    vector<unsigned long long> originalIntVec;
    vector<Fraction> originalFracVec;

    getUniqueNums(size, originalIntVec);
    getUniqueFractions(size, originalFracVec);

    // Test SelectionSort with integers
    vector<unsigned long long> intVecCopy = originalIntVec;
    chrono::high_resolution_clock::time_point start =
        chrono::high_resolution_clock::now();
    selectionSort(intVecCopy);
    chrono::high_resolution_clock::time_point end =
        chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time_span = end - start;

    csvFile << "SelectionSort,Integer," << size << "," << fixed
            << setprecision(4) << time_span.count() << endl;
    cout << "SelectionSort (Integer, " << size << ") completed!" << endl;

    // Test SelectionSort with fractions
    vector<Fraction> fracVecCopy = originalFracVec;
    start = chrono::high_resolution_clock::now();
    selectionSort(fracVecCopy);
    end = chrono::high_resolution_clock::now();
    time_span = end - start;

    csvFile << "SelectionSort,Fraction," << size << "," << fixed
            << setprecision(4) << time_span.count() << endl;
    cout << "SelectionSort (Fraction, " << size << ") completed!" << endl;
  }

  // ShellSort algorithm
  for (int size : testSize) {
    // Generate the test data
    vector<unsigned long long> originalIntVec;
    vector<Fraction> originalFracVec;

    getUniqueNums(size, originalIntVec);
    getUniqueFractions(size, originalFracVec);

    // Test ShellSort with integers
    vector<unsigned long long> intVecCopy = originalIntVec;
    chrono::high_resolution_clock::time_point start =
        chrono::high_resolution_clock::now();
    shellSort(intVecCopy);
    chrono::high_resolution_clock::time_point end =
        chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> time_span = end - start;

    csvFile << "ShellSort,Integer," << size << "," << fixed << setprecision(4)
            << time_span.count() << endl;
    cout << "ShellSort (Integer, " << size << ") completed!" << endl;

    // Test ShellSort with fractions
    vector<Fraction> fracVecCopy = originalFracVec;
    start = chrono::high_resolution_clock::now();
    shellSort(fracVecCopy);
    end = chrono::high_resolution_clock::now();
    time_span = end - start;

    csvFile << "ShellSort,Fraction," << size << "," << fixed << setprecision(4)
            << time_span.count() << endl;
    cout << "ShellSort (Fraction, " << size << ") completed!" << endl;
  }

  csvFile.close();
  cout << "All tests completed! Results saved to sorting_timing.csv" << endl;

  return 0;
}
