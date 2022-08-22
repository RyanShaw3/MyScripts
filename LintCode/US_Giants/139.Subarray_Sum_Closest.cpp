#include <vector>
#include <algorithm>
using namespace std;

class Subarray
{
public:
    int sum;
    int index;
    Subarray(int sum, int index) : sum(sum), index(index) {}
    bool operator<(const Subarray &right)
    {
        return (this->sum < right.sum || (this->sum == right.sum) && this->index < right.index);
    }
};

class Solution
{
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums)
    {
        // write your code here
        int sum = 0, n = nums.size();
        vector<Subarray> v;
        // 可能第一个元素即为答案
        v.emplace_back(Subarray(0, -1));
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            v.emplace_back(Subarray(sum, i));
        }
        // 按照子串和排序O(nlogn)
        // 相邻两个子串和的差值越小,两个子串的差的和就越靠近0
        sort(v.begin(), v.end());
        vector<int> res(2);
        int best = 1e7;
        for (int i = 1; i <= n; i++)
        {
            int tmp = abs(v[i].sum - v[i - 1].sum);
            if (tmp < best)
            {
                best = tmp;
                res[0] = min(v[i - 1].index, v[i].index) + 1;
                res[1] = max(v[i - 1].index, v[i].index);
            }
        }
        return res;
    }
};
