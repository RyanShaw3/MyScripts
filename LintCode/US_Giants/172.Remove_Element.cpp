#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem)
    {
        // write your code here
        for (vector<int>::iterator it = A.begin(); it != A.end();)
            if (*it == elem)
                it = A.erase(it);
            else
                it++;
        return A.size();
    }
};