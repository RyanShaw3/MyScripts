#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A)
    {
        // write your code here
        int minJump = 0, count = 0, n = A.size();
        for (int i = 0; i < n - 1; i++, count--)
        {
            if (count < 0)
                return 0;
            if (A[i] > count && i + count + 1 < n)
            {
                count = A[i];
                minJump++;
            }
        }
        return count >= 0 ? minJump : 0;
    }
};