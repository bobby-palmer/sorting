#include "sort.h"
#include <cstddef>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

using sorter = function<void(int[], size_t)>;

void testSort(int* arr, size_t size, sorter alg) {
  alg(arr, size); 
  for (size_t i = 0; i < size - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      cout << "TEST " << " FAILED TO SORT" << endl;
      return;
    }
  }
  cout << "passed test " << '!' << endl;
}

int main() {
  const size_t size{5};
  int arr[size] = {4, 1, 3, 2, 5};
  vector<sorter> sorts{bubbleSort, insertionSort, selectionSort, quickSort};
  for (auto sort : sorts) {
    testSort(arr, size, sort);
  }
}
