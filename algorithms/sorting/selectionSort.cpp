#include <iostream>
#include <vector>

template <typename T>
void selectionSort(std::vector<T> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            std::swap(arr[i], arr[min_idx]);
    }
}
struct Item
{
    int value;
    char label;

    // Overload the > operator for comparison
    bool operator<(const Item &other) const
    {
        return value < other.value;
    }
};

// Function to print the vector of Items
void printItems(const std::vector<Item> &items)
{
    for (const auto &item : items)
    {
        std::cout << "(" << item.value << ", " << item.label << ") ";
    }
    std::cout << std::endl;
}

int main()
{
    // Large dataset for general sorting
    std::vector<int> largeData = {
        64, 34, 25, 12, 22, 11, 90, 88, 45, 2,
        37, 5, 76, 23, 71, 13, 55, 17, 39, 30,
        27, 57, 99, 3, 66, 44, 50, 60, 19, 14,
        1, 70, 63, 89, 75, 84, 83, 7, 42, 51};

    // Dataset to check for stability
    std::vector<Item> stabilityData = {
        {4, 'A'}, {3, 'B'}, {4, 'C'}, {2, 'D'}, {1, 'E'}, {5, 'F'}, {3, 'G'}, {1, 'H'}, {2, 'I'}, {4, 'J'}};

    // Sort and print large dataset
    std::cout << "Large dataset before sorting:" << std::endl;
    for (int num : largeData)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSort(largeData);

    std::cout << "Large dataset after sorting:" << std::endl;
    for (int num : largeData)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort and print stability dataset
    std::cout << "\nStability dataset before sorting:" << std::endl;
    printItems(stabilityData);

    selectionSort(stabilityData);

    std::cout << "Stability dataset after sorting:" << std::endl;
    printItems(stabilityData);

    return 0;
}