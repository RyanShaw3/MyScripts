#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> errorNums(2);
        unordered_map<int, int> ump;
        for (auto &num : nums)
            ump[num]++;
        for (int i = 1; i <= nums.size(); i++)
        {
            if (ump[i] == 0)
                errorNums[1] = i;
            else if (ump[i] == 2)
                errorNums[0] = i;
        }
        return errorNums;
    }
};