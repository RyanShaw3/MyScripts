#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers)
    {
        // write your code here
        int n = numbers.size();
        vector<vector<int>> res;
        sort(numbers.begin(), numbers.end());

        for (int i = 0; i <= n - 3; i++)
        {
            if (i != 0 && numbers[i] == numbers[i - 1])
                continue;

            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (j > i + 1 && numbers[j] == numbers[j - 1])
                {
                    j++;
                    continue;
                }
                else if (k < n - 1 && numbers[k] == numbers[k + 1])
                {
                    k--;
                    continue;
                }
                int sum = numbers[i] + numbers[j] + numbers[k];
                if (sum == 0)
                {
                    res.push_back({numbers[i], numbers[j], numbers[k]});
                    j++;
                    k--;
                }
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};