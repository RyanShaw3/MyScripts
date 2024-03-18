#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        stack<int> s;
        for (auto &a : arr)
        {
            if (s.empty() || a >= s.top())
                s.emplace(a);
            else
            {
                int maxA = s.top();
                s.pop();
                while (!s.empty() && s.top() > a)
                    s.pop();
                s.emplace(maxA);
            }
        }
        return s.size();
    }
};