#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int ans = 0, cur = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](const vector<int> &left, const vector<int> &right)
             { return left[1] < right[1]; });
        for (auto &p : pairs)
        {
            if (cur < p[0])
            {
                cur = p[1];
                ans++;
            }
        }
        return ans;
    }
};