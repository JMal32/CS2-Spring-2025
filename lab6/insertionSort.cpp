#include <iostream>
#include <vector>

using namespace std;

vector<int> getSubArray(const vector<int>& arr, int start, int end){
  vector<int> subarray;
  for (int i = start; i <= end && i < arr.size(); i++) {
    subarray.push_back(arr[i]);
  }
  return subarray;
}

int main(){


}
