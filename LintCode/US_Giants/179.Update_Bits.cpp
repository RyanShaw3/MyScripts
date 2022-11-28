class Solution
{
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j)
    {
        // write your code here
        int one = ~0;
        int mask = 0; // 掩码,掩盖n的第i位到第j位
        if (j < 31)
        {
            int left = one << (j + 1);
            int right = (1 << i) - 1;
            mask = left | right;
        }
        else
            mask = (1 << i) - 1;
        return (n & mask) | (m << i);
    }
};