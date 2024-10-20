#include <iostream>
#include <vector>
int linearSearch(std::vector<int> &arr, int target)
{
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int target = 0;

    std::vector<int> largeData = {
        64, 34, 25, 12, 22, 11, 90, 88, 45, 2,
        37, 5, 76, 23, 71, 13, 55, 17, 39, 30,
        27, 57, 99, 3, 66, 44, 50, 60, 19, 14,
        1, 70, 63, 89, 75, 84, 83, 7, 42, 51};

    std::cout << "Enter the value to find: ";
    std::cin >> target;

    int result = linearSearch(largeData, target);

    if (result == -1)
    {
        std::cout << "Not Found\n";
        return 0;
    }

    std::cout << "\nValue " << target << " is at index " << result;
    std::cout << std::endl;

    return 0;
}
