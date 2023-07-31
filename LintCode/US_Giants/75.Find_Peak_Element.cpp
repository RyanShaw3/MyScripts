#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A)
    {
        // write your code here
        int n = A.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (A[mid] <= A[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};