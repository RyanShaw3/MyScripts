#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans;
        for (int i = 1; i < n - k; i++)
            ans.emplace_back(i);
        for (int i = n - k, j = n; i <= j; i++, j--)
        {
            ans.emplace_back(i);
            if (i != j)
                ans.emplace_back(j);
        }
        return ans;
    }
};

// 属于思维题了，想不出来