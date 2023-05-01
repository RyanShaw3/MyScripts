#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int atoi(string &s)
    {
        // write your code here
        int sign = 1, i = 0, len = s.size();
        while (i < len && s[i] == ' ')
            i++;
        long long int res = 0;
        if (i != len)
        {
            if (s[i] == '+' || s[i] == '-')
                sign = (s[i++] == '-' ? -1 : 1);
            while (s[i] >= '0' && s[i] <= '9')
            {
                res = res * 10 + s[i] - '0';
                // 越界处理
                if (sign == -1 && -res < INT_MIN)
                    return -2147483648;
                else if (sign == 1 && res > INT_MAX)
                    return 2147483647;
                i++;
            }
            return res * (long long int)sign;
        }
        return 0;
    }
};