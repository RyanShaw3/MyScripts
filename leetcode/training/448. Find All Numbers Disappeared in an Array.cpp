#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &num : nums)
        {
            int t = (num - 1) % n;
            nums[t] += n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[i] <= n)
                ans.emplace_back(i + 1);
        return ans;
    }
};
// 将nums自身当成哈希表，不使用额外的空间，很巧妙