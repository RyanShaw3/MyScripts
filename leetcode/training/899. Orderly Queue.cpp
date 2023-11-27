#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {

        if (k == 1)
        {
            string ans = s;
            for (int i = 0; i < s.size(); i++)
            {
                s = s.substr(1) + s[0];
                if (s < ans)
                    ans = s;
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
// 脑筋急转弯？？？