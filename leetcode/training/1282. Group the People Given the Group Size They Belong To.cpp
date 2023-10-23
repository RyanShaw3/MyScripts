#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < groupSizes.size(); i++)
            ump[groupSizes[i]].emplace_back(i);
        vector<vector<int>> ans;
        for (auto &[k, v] : ump)
        {
            int num = v.size() / k;
            for (int i = 0; i < num; i++)
            {
                vector<int> group;
                for (int j = 0; j < k; j++)
                    group.emplace_back(v[i * k + j]);
                ans.emplace_back(group);
            }
        }
        return ans;
    }
};