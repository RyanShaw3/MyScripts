#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    int ans = INT_MAX;

public:
    int kSimilarity(string s1, string s2)
    {
        dfs(s1, s2, 0, s1.size(), 0);
        return ans;
    }
    void dfs(string &s1, string &s2, int cur, int n, int count)
    {
        if (cur == n)
        {
            ans = min(ans, count);
            return;
        }
        if (count >= ans)
            return;
        if (s1[cur] != s2[cur])
        {
            for (int i = cur + 1; i < n; i++)
            {
                if (s1[i] == s2[cur])
                {
                    swap(s1[i], s1[cur]);
                    dfs(s1, s2, cur + 1, n, count + 1);
                    swap(s1[i], s1[cur]);
                }
            }
        }
        else
            dfs(s1, s2, cur + 1, n, count);
        return;
    }
};