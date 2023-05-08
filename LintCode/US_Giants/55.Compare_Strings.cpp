#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B)
    {
        // write your code here
        if (A.length() < B.length())
            return false;
        int set[26] = {0};
        for (int i = 0; i < A.length(); i++)
            set[A[i] - 'A']++;
        for (int i = 0; i < B.length(); i++)
            set[B[i] - 'A']--;
        for (int i = 0; i < 26; i++)
            if (set[i] < 0)
                return false;
        return true;
    }
};