#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums)
    {
        // write your code here
        int count = 0, n = nums.size();
        vector<int>::iterator i, j;
        for (i = nums.begin(), j = nums.begin(); j != nums.end();)
        {
            if (*j == *i)
            {
                count++;
                if (count > 2)
                    j = nums.erase(j);
                else
                    j++;
            }
            else
            {
                count = 0;
                i = j;
            }
        }
        return nums.size();
    }
};