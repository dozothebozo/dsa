#include <cstddef>
#include <iostream>

template <typename T>
void swap(T arr[], std::size_t firstIndex, std::size_t secondIndex)
{
    T temp{arr[secondIndex]};
    arr[secondIndex] = arr[firstIndex];
    arr[firstIndex] = temp;
}

template <typename T>
void bubbleSort(T arr[], std::size_t size)
{
    for (std::size_t i{size - 1}; i > 0; --i)
        for (std::size_t j{0}; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, (j + 1), j);
            }
        }
}

template <typename T>
void selectionSort(T arr[], std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i)
    {
        std::size_t minIndex{i};
        for (std::size_t j{i + 1}; j < size; ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (i != minIndex)
        {
            swap(arr, minIndex, i);
        }
    }
}

template <typename T>
void insertionSort(T arr[], std::size_t size)
{
    for (std::size_t i{1}; i < size; ++i)
    {
        T temp{arr[i]};
        std::size_t j{i};
        while (j > 0 && temp < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = temp;
    }
}

template <typename T>
std::size_t pivot(T arr[], std::size_t pivotIndex, std::size_t endIndex)
{
    std::size_t swapIndex{pivotIndex};
    for (std::size_t i{pivotIndex + 1}; i <= endIndex; ++i)
    {
        if (arr[i] < arr[pivotIndex])
        {
            swapIndex++;
            swap(arr, swapIndex, i);
        }
    }
    swap(arr, pivotIndex, swapIndex);
    return swapIndex;
}

template <typename T>
void quickSort(T arr[], std::size_t leftIndex, std::size_t rightIndex)
{
    if (leftIndex >= rightIndex)
        return;
    std::size_t pivotIndex{pivot(arr, leftIndex, rightIndex)};
    quickSort(arr, leftIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, rightIndex);
}

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
