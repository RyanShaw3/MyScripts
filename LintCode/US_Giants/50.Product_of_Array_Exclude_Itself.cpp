#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums)
    {
        // write your code here
        int len = nums.size();
        // left[i] = nums[0] * nums[1] * ... * nums[i-1]
        // right[i] = nums[n-1] * nums[n-2] * ... * nums[i+1]
        long long *left = new long long[len], *right = new long long[len];
        left[0] = 1;
        right[len - 1] = 1;
        for (int i = 1; i < len; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
            right[len - 1 - i] = right[len - i] * nums[len - i];
        }
        vector<long long> res(len, 0);
        for (int i = 0; i < len; i++)
            res[i] = left[i] * right[i];
        return res;
    }
};