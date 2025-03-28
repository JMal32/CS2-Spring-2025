#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sequentialSearch(const vector<int>& alist, int item){
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
