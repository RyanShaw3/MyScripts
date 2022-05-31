#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums)
    {
        // write your code here
        int i = 0, len = nums.size();
        if (len <= 1)
            return len;
        for (int j = 1; j < len; j++)
        {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        }
        return i + 1;
    }
};