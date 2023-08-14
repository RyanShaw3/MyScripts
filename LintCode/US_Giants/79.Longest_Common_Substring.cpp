#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B)
    {
        // write your code here
        int m = A.length(), n = B.length(), res = 0;
        if (m == 0 || n == 0)
            return 0;
        // 初始化二维数组
        int **dp = new int *[m+1];
        for (int i = 0; i < m+1; i++)
            dp[i] = new int[n+1];
        // dp
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(dp[i][j], res);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return res;
    }
};