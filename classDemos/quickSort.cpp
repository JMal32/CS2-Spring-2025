#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void quickSort(int list[], int lo, int hi) {
  if (lo < hi) {
    int pivotIndex = partition(list, lo, hi);
    quickSort(list, lo, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, hi);
  }
}

unsigned long long qsPartition(int list[], int lo, int hi) {
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
