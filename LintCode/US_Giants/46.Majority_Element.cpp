#include <vector>
#include <algorithm>
using namespace std;

// method 1 排序
class Solution
{
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums)
    {
        // write your code here
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// method 2 Boyer–Moore majority vote algorithm
class Solution
{
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums)
    {
        // write your code here
        int mode = 0, count = 0;
        for (auto num : nums)
        {
            if (count == 0)
                mode = num;
            if (mode == num)
                count++;
            else
                count--;
        }
        return mode;
    }
};