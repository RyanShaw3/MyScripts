class Solution
{
public:
    /**
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n)
    {
        // write your code here
        // n!=0 && n>0 && n is power of 2
        return n && !(n >> 31) && !(n & (n - 1));
    }
};