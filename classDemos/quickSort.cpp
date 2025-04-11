#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

unsigned long long quickSort(unsigned long long list, int lo, int hi) {
  if (lo < hi) {
    int pivotIndex = partition(list, lo, hi);
  }
}

unsigned long long partition(int list[], int lo, int hi) {
  int pivot = list[hi];
}

/* Psuedocode for this algorithm:

  function quickSort(array, low, high)
  if low < high then
    pivot_index = partition(array, low, high)
    quickSort(array, low, pivot_index - 1)
    quickSort(array, pivot_index + 1, high)
  end if
end function

function partition(array, low, high)
  pivot = array[high]
  i = low - 1
  for j = low to high - 1 do
    if array[j] <= pivot then
      i = i + 1
      swap array[i] with array[j]
    end if
  end for
  swap array[i + 1] with array[high]
  return i + 1
end function */
