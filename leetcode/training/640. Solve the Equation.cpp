#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string solveEquation(string equation)
    {
        int i = 0, n = equation.size(), sign = 1, left = 0;
        int a = 0, b = 0;
        while (i < n)
        {
            if (equation[i] == '=')
            {
                if (left < i)
                {
                    int val = stoi(equation.substr(left, i - left));
                    b += sign * val;
                }
                sign = -1;
                left = i + 1;
            }
            else if ((equation[i] == '+' || equation[i] == '-') && i != left)
            {
                int val = stoi(equation.substr(left, i - left));
                b += sign * val;
                left = i;
            }
            else if (equation[i] == 'x')
            {
                int val = equation[left] == '-' ? -1 : 1;
                if (i > left + 1 || (i == left + 1 && equation[left] != '+' && equation[left] != '-'))
                    val = stoi(equation.substr(left, i - left));
                a += sign * val;
                left = i + 1;
            }
            i++;
        }
        if (equation[n - 1] != 'x')
        {
            int val = stoi(equation.substr(left, i - left));
            b += sign * val;
        }
        if (a == 0)
        {
            if (b == 0)
                return "Infinite solutions";
            return "No solution";
        }
        return "x=" + to_string(-b / a);
    }
};