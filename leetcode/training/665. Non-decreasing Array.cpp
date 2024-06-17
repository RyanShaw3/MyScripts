#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool flag = true;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (flag)
                {
                    if (i == 0)
                        nums[0] = nums[1];
                    else if (nums[i - 1] > nums[i + 1])
                        nums[i + 1] = nums[i];
                    else
                        nums[i] = nums[i - 1];
                    flag = false;
                }
                else
                    return false;
            }
        }
        return true;
    }
};