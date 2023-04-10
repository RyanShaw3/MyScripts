#include <vector>
#include <unordered_map>
using namespace std;

// method 1 hash table
class Solution
{
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int> &nums)
    {
        // write your code here
        unordered_map<int, int> ump;
        for (int num : nums)
            ump[num]++;
        int major = 0, count = 0;
        for (auto i = ump.begin(); i != ump.end(); i++)
            if (i->second > count)
            {
                major = i->first;
                count = i->second;
            }
        return major;
    }
};

// method 2 Boyer–Moore majority vote algorithm
class Solution
{
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int> &nums)
    {
        // write your code here
        int mode1 = 0, mode2 = 0, count1 = 0, count2 = 0;
        for (int num : nums)
        {
            if (mode1 == num)
                count1++;
            else if (mode2 == num)
                count2++;
            else if (count1 == 0)
            {
                mode1 = num;
                count1++;
            }
            else if (count2 == 0)
            {
                mode2 = num;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for (int num : nums)
        {
            if (mode1 == num)
                count1++;
            else if (mode2 == num)
                count2--;
        }
        return count1 > nums.size() / 3 ? mode1 : (count2 > nums.size() / 3 ? mode2 : 0);
    }
};