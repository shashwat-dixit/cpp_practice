#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right, mid);
    }
}

void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {
        64, 34, 25, 12, 22, 11, 90, 88, 45, 2,
        37, 5, 76, 23, 71, 13, 55, 17, 39, 30,
        27, 57, 99, 3, 66, 44, 50, 60, 19, 14,
        1, 70, 63, 89, 75, 84, 83, 7, 42, 51};
    std::cout << "Original array: ";
    printArray(arr);
    mergeSort(arr, 0, arr.size() - 1);
    std::cout << "Sorted array: ";
    printArray(arr);
    return 0;
}