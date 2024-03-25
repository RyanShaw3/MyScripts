#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        if (s.size() <= 2)
            return s;
        int count = 0, left = 0;
        vector<string> substring;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                count++;
            else
            {
                count--;
                if (count == 0)
                {
                    substring.emplace_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                    left = i + 1;
                }
            }
        }
        sort(substring.begin(), substring.end(), greater<string>());       // greater<string>()
        return accumulate(substring.begin(), substring.end(), string("")); // init要用空的string，而不是""
    }
};