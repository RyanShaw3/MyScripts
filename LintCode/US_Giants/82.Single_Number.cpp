#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A)
    {
        // write your code here
        int res = 0;
        for (auto a : A)
            res ^= a; // 出现两次的因为异或而变成0,只留下出现一次的数
        return res;
    }
};