class SVNRepo
{
public:
    static bool isBadVersion(int k);
};

class Solution
{
public:
    /**
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n)
    {
        // write your code here
        unsigned int left = 1, right = n;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (SVNRepo::isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};