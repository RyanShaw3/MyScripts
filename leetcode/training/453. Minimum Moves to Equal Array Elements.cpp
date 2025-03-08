#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int min_num = *min_element(nums.begin(), nums.end()), ans = 0;
        for (auto &num : nums)
            ans += num - min_num;
        return ans;
    }
};
// 把n-1个数加1换成1个数减1就好理解了