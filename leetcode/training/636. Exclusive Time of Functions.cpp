#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        stack<pair<int, int>> s;
        vector<int> ans(n, 0);
        for (auto &log : logs)
        {
            int id, timestamp;
            char a[10];
            sscanf(log.c_str(), "%d:%[^:]:%d", &id, a, &timestamp); // %[^:]表示连续读取字符，除非遇到引号
            if (a[0] == 's')
            {
                if (!s.empty())
                {
                    ans[s.top().first] += timestamp - s.top().second;
                    s.top().second = timestamp;
                }
                s.emplace(id, timestamp);
            }
            else
            {
                auto t = s.top();
                s.pop();
                ans[t.first] += timestamp - t.second + 1;
                if (!s.empty())
                    s.top().second = timestamp + 1;
            }
        }
        return ans;
    }
};