#include "sorting.h"
#include <cstddef>
#include <iostream>

int main()
{
    int arr[]{4, 6, 1, 7, 3, 2, 5};
    // bubbleSort(arr, (sizeof(arr) / sizeof(arr[0])));
    // selectionSort(arr, (sizeof(arr) / sizeof(arr[0])));
    // insertionSort(arr, (sizeof(arr) / sizeof(arr[0])));
    quickSort(arr, 0, (sizeof(arr) / sizeof(arr[0]) - 1));
    for (const auto& x : arr)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
