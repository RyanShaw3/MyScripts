class Solution
{
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b)
    {
        // write your code here
        int count = 0, c = a ^ b, i = 32;
        do
        {
            count += c & 1;
        } while ((c >>= 1) && --i);
        return count;
    }
};

// #include <bitset>
// using namespace std;

// class Solution
// {
// public:
//     /**
//      * @param a: An integer
//      * @param b: An integer
//      * @return: An integer
//      */
//     int bitSwapRequired(int a, int b)
//     {
//         // write your code here
//         bitset<32> c(a ^ b);
//         return c.count();
//     }
// };