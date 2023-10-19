#include <cstddef>
#include <algorithm>
inline void bubbleSort(int arr[], size_t size) {
  size_t sorted = 0;
  while (sorted < size) {
    for (size_t i = size - 1; i > sorted; --i ) {
      if(arr[i] < arr[i - 1]) {
        int temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
      }
    }
    sorted++;
  }
}; // bubbleSort()

inline void selectionSort(int arr[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    size_t smallest = i;
    for (size_t j = i; j < size; ++j) {
      if (arr[j] < arr[smallest]) {
        smallest = j;
      }
    }
    int temp = arr[smallest];
    arr[smallest] = arr[i];
    arr[i] = temp;
  }
}; // selectionSort

inline void insertionSort(int arr[], size_t size) {
  size_t min = 0;
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] < arr[min]) {
      min = i;
    }
  }
  int temp = arr[min];
  arr[min] = arr[0];
  arr[0] = temp;
  for (size_t i = 1; i < size; ++i) {
    int v = arr[i];
    size_t j = i;
    while (arr[j - 1] > v) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = v;
  }
}; // insertionSort

namespace {
  inline int* partition(int arr[], size_t size) {
    int* end = arr + size - 1;
    int* pivot = end--; 
    while (arr <= end) {
      if (*arr < *pivot) {
        ++arr;
      } else if (*pivot < *end) {
        --end;
      } else {
        std::swap(*arr, *end);
      }
    }
    std::swap(*pivot, *arr);
    return arr;
  }
}; // private partition method

inline void quickSort(int arr[], size_t size) {
  if (size <= 1) {
    return;
  }
  int* end = arr + size;
  auto mid = partition(arr, size);
  quickSort(arr, mid - arr);
  quickSort(mid + 1, end - (mid + 1));
}; // quickSort
