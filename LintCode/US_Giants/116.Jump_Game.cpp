#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A)
    {
        // write your code here
        int jump = 0, n = A.size();
        for (int i = 0; i < n - 1; i++, jump--)
        {
            if (jump < 0)
                return false;
            if (A[i] > jump)
                jump = A[i];
        }
        return true;
    }
};