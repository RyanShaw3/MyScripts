class Solution
{
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n)
    {
        // write your code here
        int *res = new int[m + n];
        int i, j, k;
        for (i = 0, j = 0, k = 0; i < m && j < n; k++)
        {
            if (A[i] < B[j])
                res[k] = A[i++];
            else
                res[k] = B[j++];
        }
        while (i != m)
            res[k++] = A[i++];
        while (j != n)
            res[k++] = B[j++];
        for (i = 0; i < m + n; i++)
            A[i] = res[i];
    }
};