// Finds maximum subarray sum.
#include <iostream>
#include <algorithm>

class Kadanes
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            maxEndingHere = std::max(nums[i], nums[i] + maxEndingHere);
            maxSoFar = std::max(maxEndingHere, maxSoFar);
        }
        return maxSoFar;
    }
};

int main()
{
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Kadanes solution;
    int result = solution.maxSubArray(arr); // Returns 6 (subarray {4,-1,2,1})
    std::cout << "Output: " << result;
    std::cout << std::endl;
    return 0;
}
