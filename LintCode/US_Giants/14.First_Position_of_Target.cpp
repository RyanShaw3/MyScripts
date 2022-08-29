#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target)
    {
        // write your code here
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // 找target的第一个位置==找第一个大于等于target的数的下标
            if (nums[mid] >= target)
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if (nums[ans] == target)
            return ans;
        return -1;
    }
};