#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target)
    {
        // write your code here
        sort(numbers.begin(), numbers.end());
        int res = 1e7, n = numbers.size();
        for (int i = 0; i <= n - 3; i++)
        {
            // 相同的情况可以跳过
            if (i != 0 && numbers[i] == numbers[i - 1])
                continue;
            // 双指针，i固定了a，j和k遍历b和c
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = numbers[i] + numbers[j] + numbers[k];
                int d = abs(sum - target);
                if (d == 0)
                    return sum;
                else if (d < abs(res - target))
                    res = sum;

                if (sum < target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};