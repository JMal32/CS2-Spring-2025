#include <iostream>
#include <vector>

using namespace std;

// subarray function i was messing around with in class to potentially use
vector<int> getSubArray(const vector<int> &arr, int start, int end) {
  vector<int> subarray;
  for (int i = start; i <= end && i < arr.size(); i++) {
    subarray.push_back(arr[i]);
  }
  return subarray;
}

void insersionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {}
