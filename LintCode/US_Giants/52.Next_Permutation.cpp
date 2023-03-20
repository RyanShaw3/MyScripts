#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums)
    {
        // write your code here
        int i, j, a, n = nums.size();
        for (i = n - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1])
            {
                a = i;
                break;
            }
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        for (j = n - 1; j > a; j--)
            if (nums[j] > nums[a])
            {
                swap(nums[a], nums[j]);
                sort(nums.begin() + a + 1, nums.end());
                break;
            }
        return nums;
    }
};