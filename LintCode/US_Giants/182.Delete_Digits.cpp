#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: A positive integer which has N digits, A is a string
     * @param k: Remove k digits
     * @return: A string
     */
    string DeleteDigits(string &A, int k)
    {
        // write your code here
        // 贪心+单调栈,用双端队列代替栈
        vector<char> s;
        for (auto a : A)
        {
            while (s.size() > 0 && s.back() > a && k)
            {
                s.pop_back();
                k--;
            }
            s.push_back(a);
        }
        for (; k; k--)
            s.pop_back();
        string res = "";
        // 删除前导零
        bool isLeadingZero = true;
        for (auto digit : s)
        {
            if (isLeadingZero && digit == '0')
                continue;
            isLeadingZero = false;
            res += digit;
        }
        return res == "" ? "0" : res;
    }
};