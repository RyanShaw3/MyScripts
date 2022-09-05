class Solution
{
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n)
    {
        // write your code here
        // 快速幂 a是底数 n是次数
        long long base = a, power = n, ans = 1;
        while (power > 0)
        {
            if (power & 1) // if power % 2 == 1
                ans = ans * base % b;
            power >>= 1; // power /= 2
            base = base * base % b;
        }
        return ans % b;
    }
};