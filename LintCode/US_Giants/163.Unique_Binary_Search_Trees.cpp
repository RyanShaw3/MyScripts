#include <vector>
using namespace std;

// method 1 DP
class Solution
{
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n)
    {
        // write your code here
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                G[i] += G[j - 1] * G[i - j];
        return G[n];
    }
};

// method 2 卡特兰数
class Solution
{
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n)
    {
        // write your code here
        long long C = 1;
        for (int i = 0; i < n; i++)
            C = C * 2 * (2 * i + 1) / (i + 2);
        return (int)C;
    }
};

// method 3 打表
class Solution
{
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n)
    {
        // write your code here
        int arr[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};
        return arr[n];
    }
};