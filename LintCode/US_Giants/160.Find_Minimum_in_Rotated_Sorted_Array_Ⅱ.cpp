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
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[left] < nums[right]) // no ratition
                return nums[left];
            if (nums[mid] > nums[left]) // the min value is in (mid,right]
                left = mid + 1;
            else if (nums[mid] < nums[left]) // the min value is in [left,mid]
                right = mid;
            else // the min value is in (left,mid]
                left++;
        }
        return nums[left];
    }
};