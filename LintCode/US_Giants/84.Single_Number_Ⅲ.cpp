#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> &A)
    {
        // write your code here
        int result = 0;
        for (int a : A)
            result ^= a; // result=ans1^ans2

        int w = 1;
        while ((result & w) == 0)
            w <<= 1;
        // 分组异或
        int ans1 = 0, ans2 = 0;
        for (int a : A)
        {
            if (a & w)
                ans1 ^= a;
            else
                ans2 ^= a;
        }
        return vector<int>{ans1, ans2};
    }
};