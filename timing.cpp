
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <random>

using namespace std;
using namespace std::chrono;

int sumOfN(int n) {
  int theSum = 0;
  for (int i = 1; i <= n; i++) {
    theSum += i;
  }
  return theSum;
}

bool anag1(const string s1, const string s2) {
  vector<char> vlist;
  int pos1 = 0; bool stillOK = true;
  if (s1.length() != s2.length()) {return false;}
  
  for (int i=0; i<s2.length(); i++) {
    vlist.push_back(s2[i]); } // init vlist
  while (pos1 < s1.size() && stillOK) { // find char in vlist
    int pos2 = 0; bool found = false;
  while (pos2 < vlist.size() && !found) {
    if (s1[pos1] == vlist.at(pos2)) {
      found = true;
    } else {
        pos2 += 1;
    }
  }
  if (found) {
    vlist.at(pos2) = ' ';
  } else {
      stillOK = false;
  }
  pos1 += 1;
  }
  return stillOK;
}

bool anagramSol2(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    
    string alist1 = s1;
    string alist2 = s2;
    
    sort(alist1.begin(), alist1.end());
    sort(alist2.begin(), alist2.end());
    
    size_t pos = 0;
    bool matches = true;
    while (pos < s1.size() && matches) {
        if (alist1[pos] == alist2[pos]) {
            pos++;
        } else {
            matches = false;
        }
    }
    return matches;
}

void timeSumofN() {
  vector<int> n;
  vector<double> time_results;

  //Increment n by 100000
  for (int num = 100000; num <= 1000000; num += 100000) {
    n.push_back(num);

    double total_time = 0.0;

    //Running it 10 times
    for (int i = 0; i < 10; i++) {
      high_resolution_clock::time_point start = high_resolution_clock::now();
      sumOfN(num);      
      high_resolution_clock::time_point end = high_resolution_clock::now(); 
      duration<double, std::milli> time_span = end - start;
      total_time += time_span.count();
    }

    double avg_time = total_time / 10;
    time_results.push_back(avg_time);

    cout << num << "," << avg_time << endl;    
  }
}
 int main() {
   timeSumofN();
   return 0;
 }
