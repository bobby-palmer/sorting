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
