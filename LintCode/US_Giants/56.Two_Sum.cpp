#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // write your code here
        unordered_map<int, int> ump;
        int len = numbers.size();
        for (int i = 0; i < len; i++)
        {
            int tmp = target - numbers[i];
            auto it = ump.find(tmp);
            if (it != ump.end())
                return vector<int>{it->second, i};
            else if (ump.find(numbers[i]) == ump.end())
                ump[numbers[i]] = i;
        }
    }
};