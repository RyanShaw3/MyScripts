#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A)
    {
        // write your code here
        unordered_map<int, int> ump;
        for (int a : A)
            ump[a]++;
        for (auto i = ump.begin(); i != ump.end(); i++)
            if (i->second == 1)
                return i->first;
        return 0;
    }
};