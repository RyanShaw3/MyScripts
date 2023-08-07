#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs)
    {
        // write your code here
        int count = strs.size();
        if (count == 0)
            return "";
        int maxLen = strs[0].size();
        for (int i = 1; i < count; i++)
            maxLen = this->longestCommonPrefix(strs[i], strs[i - 1], maxLen);
        return strs[0].substr(0, maxLen);
    }
    int longestCommonPrefix(string &a, string &b, int maxLen)
    {
        int index = 0, len = min((int)min(a.size(), b.size()), maxLen);
        while (index < len && a[index] == b[index])
            index++;
        return index;
    }
};