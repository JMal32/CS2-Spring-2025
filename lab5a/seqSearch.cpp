#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

bool sequentialSearch(const vector<unsigned long long>& alist, unsigned long long item){
  int pos = 0;
  bool found = false;
  
  while (pos < alist.size() && !found) {
    if (alist[pos] == item) {
      found = true;
    } else {
      pos = pos+1;
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
  ofstream csvFile("seq_timing.csv");
  csvFile << "Size,SearchType,Time(milliseconds)" << endl;

  cout << "Generating Timing Data..." << endl;
  
  vector<int> testSize = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000};
  int count = 10;

  for (int size : testSize) {
    vector<unsigned long long> vec;
    getUniqueNums(size + 1000, vec); // This is where we generate 1000 extra ints
  
    // Copying those unique nums in a new vector except for the last 1000
    vector<unsigned long long> uniqueVec(vec.begin(), vec.end() - 1000); 
  
    // First timing where we're searching for integers NOT in the vector
    vector<unsigned long long> notInVec(vec.end() - 1000, vec.end());
    
    auto start1 = chrono::high_resolution_clock::now();
      for (unsigned long long num : notInVec) {
        bool found = sequentialSearch(uniqueVec, num);
      }
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> totalNotInVec = end1 - start1;
    
    // Second timing where we're searching for integer IN the vector
    vector<unsigned long long> inVec;
    int selectNum = min(1000, (int)uniqueVec.size());
    for (int i = 0; i< selectNum; i++) {
      int randIndex = rand() % uniqueVec.size();
      inVec.push_back(uniqueVec[randIndex]);
    }
    
    auto start2 = chrono::high_resolution_clock::now();
    for (unsigned long long num : inVec) {
    bool found = sequentialSearch(uniqueVec, num);
    }
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> totalInVec = end2 - start2;
    
    csvFile << size << ",NotInVec," << fixed << setprecision(4) << totalNotInVec.count() << endl;
    csvFile << size << ",InVec," << fixed << setprecision(4) << totalInVec.count() << endl;
  }
  csvFile.close();
  return 0;
}
