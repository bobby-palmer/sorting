#include "sort.h"
#include <cstddef>
#include <iostream>
using namespace std;

void testSort(int* arr, size_t size, string name, void (*sort)(int[], size_t)) {
  sort(arr, size); 
  for (size_t i = 0; i < size - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      cout << "TEST " << name << " FAILED TO SORT" << endl;
      return;
    }
  }
  cout << "passed test " << name << '!' << endl;
}

int main() {
  const size_t size{5};
  int arr[size] = {4, 1, 3, 2, 5};
  testSort(arr, size, "BubbleSort", bubbleSort);
  testSort(arr, size, "SelectionSort", selectionSort);
  testSort(arr, size, "InsertionSort", insertionSort);
}
