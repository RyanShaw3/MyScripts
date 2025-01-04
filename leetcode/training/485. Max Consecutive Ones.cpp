#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        nums.emplace_back(0);
        int ans = 0, t = 0;
        for (auto &i : nums)
        {
            if (i == 1)
                t++;
            else if (t > ans)
            {
                ans = t;
                t = 0;
            }
            else
                t = 0;
        }
        return ans;
    }
};