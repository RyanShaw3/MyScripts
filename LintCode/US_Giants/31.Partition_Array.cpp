#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k)
    {
        // write your code here
        int n = nums.size();
        if (n == 0)
            return 0;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            while (i <= j && nums[i] < k)
                i++;
            while (i <= j && nums[j] >= k)
                j--;
            if (i <= j)
                swap(nums[i++], nums[j--]);
        }
        return i;
    }
};