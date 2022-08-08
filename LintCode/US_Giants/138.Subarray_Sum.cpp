#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums)
    {
        // write your code here
        int i, sum = 0, len = nums.size();
        unordered_map<int, int> ump;
        for (i = 0; i < len; i++)
        {
            sum += nums[i];
            if (ump.find(sum) != ump.end())
                return vector<int>{ump[sum]+1, i};
            ump[sum] = i;
        }
        return vector<int>{0, i - 1};
    }
};