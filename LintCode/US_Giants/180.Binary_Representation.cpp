#include <string>
using namespace std;

class Solution
{
public:
    /**
     * @param n: Given a decimal number that is passed in as a string
     * @return: A string
     */
    string binaryRepresentation(string &n)
    {
        // write your code here
        int intPart = stoi(n);
        double decPart = 0;
        if (n.find('.') != string::npos) // 有小数部分
            decPart = stod(n.substr(n.find('.')));
        string intStr = "", decStr = "";

        do
        {
            intStr.insert(0, to_string(intPart & 1));
        } while (intPart >>= 1);

        int i;
        for (i = 0; i < 32; i++)
        {
            if (decPart == 0)
                break;
            decPart *= 2;
            if (decPart >= 1.0)
            {
                decStr += '1';
                decPart -= 1.0;
            }
            else
                decStr += '0';
        }
        if (i == 0)
            return intStr;
        else if (decPart == 0)
            return intStr + '.' + decStr;
        return "ERROR";
    }
};