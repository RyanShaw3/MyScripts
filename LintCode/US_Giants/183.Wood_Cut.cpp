#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k)
    {
        // write your code here
        // unsigned int avoid overflow, L=[21474836544, 21474836545, 21474836546, 21474836547], k=4
        unsigned int left = 1, right = 0, result = 0;
        for (unsigned int len : L)
            right = max(right, len);
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int n = getPieces(L, mid);
            if (n >= k)
            {
                result = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return result;
    }
    int getPieces(vector<int> &L, int l)
    {
        int n = 0;
        for (auto len : L)
            n += len / l;
        return n;
    }
};