#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string strNum = to_string(num);
        int n = strNum.size();
        int maxNum = num;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(strNum[i], strNum[j]);
                maxNum = max(maxNum, stoi(strNum));
                swap(strNum[i], strNum[j]);
            }
        }
        return maxNum;
    }
};

// 官方题解的贪心做法很巧妙，没想出来