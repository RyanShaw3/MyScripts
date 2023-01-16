#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: An array of integers
     * @return: An integer
     */
    int firstMissingPositive(vector<int> &A)
    {
        // write your code here
        // 结果只能在[1,n+1]中，将A作为哈希表就可以实现O(1)的空间复杂度
        // 预处理:将所有的非正数改为n+1
        // 对于[1,n]中的数，将A[i-1]对应的数字标为负数，即为做标记
        int n = A.size();
        for (int i = 0; i < n; i++)
            if (A[i] <= 0)
                A[i] = n + 1;
        for (int i = 0; i < n; i++)
        {
            int num = abs(A[i]);
            if (num <= n)
                A[num - 1] = -abs(A[num - 1]);
        }
        for (int i = 0; i < n; i++)
            if (A[i] > 0)
                return i + 1;
        return n + 1;
    }
};