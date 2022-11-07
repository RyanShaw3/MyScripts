#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs)
    {
        // write your code here
        unordered_map<string, vector<string>> ump;
        // 如果两个字符串互为字母异位词，将他们排序后应该是一样的
        // 所以使用哈希表存储每一组字母异位词
        // 将字符串排序后的结果作为key，字符串作为value
        for (string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            ump[key].emplace_back(str);
        }
        vector<string> ans;
        unordered_map<string, vector<string>>::iterator it;
        // 单个字符串成组的不用输出
        for (it = ump.begin(); it != ump.end(); it++)
            if (it->second.size() > 1)
                ans.insert(ans.end(), it->second.begin(), it->second.end());
        return ans;
    }
};