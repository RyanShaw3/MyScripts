#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums)
    {
        // write your code here
        vector<string> strNums;
        for (auto num : nums)
            strNums.push_back(to_string(num));
        sort(strNums.begin(), strNums.end(), [](string &a, string &b)
             { return a + b > b + a; });
        string ans = "";
        for (auto num : strNums)
            ans.append(num);
        return strNums[0] == "0" ? "0" : ans;
    }
};