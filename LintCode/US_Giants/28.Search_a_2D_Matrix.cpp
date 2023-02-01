#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // write your code here
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int row = mid / n, column = mid % n;
            if (matrix[row][column] < target)
                left = mid + 1;
            else if (matrix[row][column] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};