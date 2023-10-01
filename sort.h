#include <cstddef>
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

inline void insertionSort(int arr[], size_t size) {
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
} // insertionSort
