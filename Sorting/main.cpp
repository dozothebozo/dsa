#include <cstddef>
#include <iostream>

template <typename T>
void bubbleSort(T arr[], std::size_t size)
{
    for (std::size_t i{size - 1}; i > 0; --i)
        for (std::size_t j{0}; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp{arr[j]};
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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
            T temp{arr[i]};
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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

int main()
{
    int arr[]{6, 4, 2, 5, 1, 3};
    // bubbleSort(arr, (sizeof(arr) / sizeof(arr[0])));
    // selectionSort(arr, (sizeof(arr) / sizeof(arr[0])));
    insertionSort(arr, (sizeof(arr) / sizeof(arr[0])));
    for (const auto& x : arr)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
