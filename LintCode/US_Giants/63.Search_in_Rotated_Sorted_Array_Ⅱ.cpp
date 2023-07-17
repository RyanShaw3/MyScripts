#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean
     */
    bool search(vector<int> &A, int target)
    {
        // write your code here
        int n = A.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return true;
            if (A[mid] > A[left])
            {
                if (A[mid] > target && A[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if (A[mid] < A[left])
            {
                if (A[mid] < target && A[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
                left++;
        }
        return false;
    }
};