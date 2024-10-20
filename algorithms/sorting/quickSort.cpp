#include <iostream>
#include <vector>

// implement quicksort 3 way (dutch flag)

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partioningIndex = partition(arr, low, high);

        quickSort(arr, low, partioningIndex - 1);
        quickSort(arr, partioningIndex + 1, high);
    }
}

void printArray(const std::vector<int> &arr)
{
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    std::cout << "Unsorted array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}