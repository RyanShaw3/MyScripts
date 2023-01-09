#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // write your code here
        int g = 0, min_g = 2147483647, ans = 0, n = gas.size();
        for (int i = 0; i < n; i++)
        {
            g += gas[i] - cost[i];
            if (g < min_g)
            {
                min_g = g;
                ans = i;
            }
        }
        return g < 0 ? -1 : (ans + 1) % n;
    }
};