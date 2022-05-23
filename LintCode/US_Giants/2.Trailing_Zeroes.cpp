class Solution
{
public:
    /**
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n)
    {
        // write your code here
        long long ans = 0;
        while (n /= 5)
            ans += n;
        return ans;
    }
};