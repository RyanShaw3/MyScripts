#include <iostream>
using namespace std;

class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        if (sx == tx && sy == ty)
            return true;
        if (tx == ty)
            return false;
        while (tx > sx && ty > sy)
        {
            if (tx > ty)
                tx = tx % ty;
            else
                ty = ty % tx;
        }
        return tx < sx || ty < sy ? false : (tx == sx && ty == sy ? true : (tx == sx ? (ty - sy) % tx == 0 : (ty == sy ? (tx - sx) % ty == 0 : false)));
    }
};