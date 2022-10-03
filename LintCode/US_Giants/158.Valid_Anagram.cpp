#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t)
    {
        // write your code here
        int set[256] = {0};
        for (int i = 0; i < s.length(); i++)
            set[s[i]]++;
        for (int i = 0; i < t.length(); i++)
            set[t[i]]--;
        for (int i = 0; i < 256; i++)
            if (set[i] != 0)
                return false;
        return true;
    }
};