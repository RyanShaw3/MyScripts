#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
    {
        // write your code here
        int l1 = A.size(), l2 = B.size();
        vector<int> res(l1 + l2);
        int i, j, k;
        for (i = 0, j = 0, k = 0; i < l1 && j < l2; k++)
        {
            if (A[i] < B[j])
                res[k] = A[i++];
            else
                res[k] = B[j++];
        }
        while (i != l1)
            res[k++] = A[i++];
        while (j != l2)
            res[k++] = B[j++];
        return res;
    }
};