#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums)
    {
        // write your code here
        int n = nums.size();
        int left = 0, right = n - 1, ans = nums[n - 1];
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] <= ans)
            {
                // 一直维护一个最小的ans
                ans = nums[mid];
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};