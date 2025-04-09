#include <iostream>
#include <vector>

using namespace std;



void bubbleSort(vector<int>& alist) {
  for (int sznum = alist.size() -1; sznum > 0; sznum--) {
   for (int i = 0; i < sznum; i++) {
    if (alist[i] > alist[i+1]) {
     // swapping elements here
     int temp = alist[i];
     alist[i] = alist[i+1];
     alist[i+1] = temp;
     
   }
  }
 }
}
