#include <iostream>
using namespace std;

class Solution
{
public:
    long long f(long long x)
    {
        long long ans = 0ll;
        while (x)
        {
            x /= 5;
            ans += x;
        }
        return ans;
    }
    int preimageSizeFZF(int k)
    {
        long long left = 4ll * k, right = 5ll * k;
        while (left < right)
        {
            long long middle = (left + right) / 2;
            if (f(middle) < k)
                left = middle + 1;
            else
                right = middle;
        }
        return f(left) == k ? 5 : 0;
    }
};
// 会求阶乘后的零的个数，这题要逆着求，没想明白