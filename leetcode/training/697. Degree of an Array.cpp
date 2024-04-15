#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ump.count(nums[i]))
            {
                ump[nums[i]][0]++;
                ump[nums[i]][2] = i;
            }
            else
            {
                ump[nums[i]] = {1, i, i};
            }
        }
        int ans = 0, count = 0;
        for (auto &[_, v] : ump)
        {
            if (v[0] > count)
            {
                count = v[0];
                ans = v[2] - v[1] + 1;
            }
            else if (v[0] == count && v[2] - v[1] + 1 < ans)
                ans = v[2] - v[1] + 1;
        }
        return ans;
    }
};