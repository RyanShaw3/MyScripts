#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @param source:
     * @param target:
     * @return: return the index
     */
    int strStr(string &source, string &target)
    {
        // Write your code here
        return this->KMP(source, target);
    }
    int KMP(string &source, string &target)
    {
        int m = source.length(), n = target.length();
        int *next = new int[n + 1]();
        this->getNext(target, next);
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (j == -1 || source[i] == target[j])
            {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        delete[] next;
        if (j == n)
            return i - j;
        else
            return -1;
    }
    void getNext(string &target, int *next)
    {
        next[0] = -1;
        int i = 0, j = -1;
        while (i < target.length())
        {
            if (j == -1 || target[i] == target[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
                j = next[j];
        }
    }
};