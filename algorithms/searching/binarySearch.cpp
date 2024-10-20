#include <iostream>
#include <vector>

int binarySearchIterative(std::vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (arr[middle] == target)
        {
            return middle;
        }
        if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}

int binarySearchRecursiveHelper(std::vector<int> arr, int target, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            return binarySearchRecursiveHelper(arr, target, mid + 1, right);
        }
        else
        {
            return binarySearchRecursiveHelper(arr, target, left, mid - 1);
        }
    }

    return -1;
}

int binarySearchRecursive(std::vector<int> &arr, int target)
{
    return binarySearchRecursiveHelper(arr, target, 0, arr.size() - 1);
}
int main()
{
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 0;

    std::cout << "Enter target: ";
    std::cin >> target;

    int iterativeResult = binarySearchIterative(arr, target);
    int recursiveResult = binarySearchRecursive(arr, target);
    std::cout << std::endl;
    std::cout << "Iterative Binary Search result: " << iterativeResult << std::endl;
    std::cout << std::endl;
    std::cout << "Recursive Binary Search result: " << recursiveResult << std::endl;
    std::cout << std::endl;

    return 0;
}
