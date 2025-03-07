#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[0] * nums[1] * nums[n - 1];
        int b = nums[n - 3] * nums[n - 2] * nums[n - 1];
        return a > b ? a : b;
    }
};