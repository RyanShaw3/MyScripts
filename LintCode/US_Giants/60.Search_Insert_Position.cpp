#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target)
    {
        // write your code here
        int n = A.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right + 1;
    }
};