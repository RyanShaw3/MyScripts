#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target)
    {
        // write your code here
        sort(numbers.begin(), numbers.end());
        vector<vector<int>> quadruplets;
        int n = numbers.size();
        if (n < 4)
            return quadruplets;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && numbers[i] == numbers[i - 1])
                continue;
            // 剪枝1
            if (numbers[i] + numbers[i + 1] + numbers[i + 2] + numbers[i + 3] > target)
                break;
            // 剪枝2
            if (numbers[i] + numbers[n - 3] + numbers[n - 2] + numbers[n - 1] < target)
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && numbers[j] == numbers[j - 1])
                    continue;
                // 剪枝3
                if (numbers[i] + numbers[j] + numbers[n - 2] + numbers[n - 1] < target)
                    continue;

                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    if (k > j + 1 && numbers[k] == numbers[k - 1])
                    {
                        k++;
                        continue;
                    }
                    else if (l < n - 1 && numbers[l] == numbers[l + 1])
                    {
                        l--;
                        continue;
                    }
                    int sum = numbers[i] + numbers[j] + numbers[k] + numbers[l];
                    if (sum == target)
                    {
                        quadruplets.push_back({numbers[i], numbers[j], numbers[k], numbers[l]});
                        k++;
                        l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return quadruplets;
    }
};