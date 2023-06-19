#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target)
    {
        // write your code here
        int n = A.size();
        int left = 0, right = n - 1;
        vector<int> result = {-1, -1};
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (A[mid] == target)
            {
                // find the left margin
                int l = left, r = mid;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if (A[m] == target && (r == l || A[m - 1] < target))
                    {
                        result[0] = m;
                        break;
                    }
                    else if (A[m] < target)
                        l = m + 1;
                    else
                        r = m - 1;
                }
                // find the right margin
                l = mid, r = right;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if (A[m] == target && (r == l || A[m + 1] > target))
                    {
                        result[1] = m;
                        break;
                    }
                    else if (A[m] > target)
                        r = m - 1;
                    else
                        l = m + 1;
                }
                break;
            }
            else if (A[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return result;
    }
};