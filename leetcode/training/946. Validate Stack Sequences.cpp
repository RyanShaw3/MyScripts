#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> sta;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            sta.emplace(pushed[i]);
            while (!sta.empty() && sta.top() == popped[j])
            {
                sta.pop();
                j++;
            }
        }
        return sta.empty();
    }
};