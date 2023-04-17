#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, int k)
    {
        // write your code here
        unordered_map<int, int> ump;
        for (int num : nums)
        {
            auto it = ump.find(num);
            if (it != ump.end())
                it->second++;
            else if (ump.size() < k)
            {
                ump[num] = 1;
            }
            else
            {
                for (auto i = ump.begin(); i != ump.end();)
                {
                    i->second--;
                    if (i->second == 0)
                        i = ump.erase(i);
                    else
                        i++;
                }
            }
        }
        for (auto &mode : ump)
            mode.second = 0;
        int n = nums.size() / k;
        for (int num : nums)
        {
            auto it = ump.find(num);
            if (it != ump.end())
            {
                it->second++;
                if (it->second >= n)
                    return it->first;
            }
        }
        return -1;
    }
};