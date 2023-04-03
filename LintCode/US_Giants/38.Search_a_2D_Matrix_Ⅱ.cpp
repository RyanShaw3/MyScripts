#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // write your code here
        int m = matrix.size(), n = matrix[0].size();
        int r = m - 1, c = 0, count = 0;
        while (r >= 0 && c < n)
        {
            if (matrix[r][c] > target)
                r--;
            else if (matrix[r][c] < target)
                c++;
            else
            {
                count++;
                r--;
                c++;
            }
        }
        return count;
    }
};