#include "sort.h"
#include <cstddef>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

using sorter = function<void(int[], size_t)>;

void testSort(size_t size, sorter alg) {
  // create dynamic array of specified size
  int* arr = new int[size];

  // fill with random values
  generate(arr, arr + size, rand());

  // use sorter
  alg(arr, size); 

  // check if actually sorted
  for (size_t i = 0; i < size - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      cout << "TEST FAILED!" << endl;
      return;
    }
  }
  cout << "passed test !" << endl;
}

int main() {
  const size_t size {10};
  vector<sorter> sorts{bubbleSort, insertionSort, selectionSort, quickSort};
  for (auto sort : sorts) {
    testSort(size, sort);
  }
}
