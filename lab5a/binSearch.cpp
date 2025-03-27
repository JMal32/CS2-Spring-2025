#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;

bool binarySearch(const vector<int>& alist, int item){
  int first = 0;
  int last = alist.size() - 1; 
  bool found = false;
  while (first <= last && !found){
    int midpoint = (first + last) / 2;
    if (alist[midpoint] == item) {
      found = true;
    } else {
        if (item < alist[midpoint]) {
          last = midpoint -1;
        } else{
            first = midpoint +1;
      }
    }
  }
  return found;
}

unsigned long long getInt(int numDigits = 10) {
  unsigned long long num = 0;

  num = rand() % 9 + 1;
  for (int i = 0; i < numDigits -1; i++) {
    num = num * 10 + rand() % 10;
  }
  return num;
}

void getUniqueNums(int sz, vector<unsigned long long>& v) {
  vector<unsigned long long> tmpv;
  vector<bool> bvect;
  bvect.resize(10000000000, false); // resizing vector large enough to track 9-digit #s
  
  int ix = 0;
  while(ix < sz * 1.1 && v.size() < sz) {
    unsigned long long num = getInt(9);
    if (bvect[num] == false) {
      v.push_back(num);
      bvect[num] = true;
    }
    ix++;
  }
  bvect.resize(0);

  cout << v.size() << " unique numbers generated!" << endl;
}

int main() {
  ofstream csvFile("bin_timing.csv");
  csvFile << "Size,Time(seconds)" << endl;

  cout << "Generating Timing Data..." << endl;
  
  int initSize = 1000;
  int count = 10;

  for (int i = 0; i < count; i++) {
    int size = initSize * pow(2, i);
    vector<unsigned long long> vec;
    getUniqueNums(size + 1000, vec); // This is where we generate 1000 extra ints
    
    vector<unsigned long long> uniqueVec(vec.begin(), vec.end() - 1000); // Copying those unique nums in a new vector except for the last 1000
    
    sort(uniqueVec.begin(), uniqueVec.end());

   

    auto start = chrono::high_resolution_clock::now();
    binarySearch(int uniqueVec, int item);    
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> totalTime = end - start;
    
    csvFile << size << "," << totalTime.count() << endl;
  }
  csvFile.close();
  return 0;
}

