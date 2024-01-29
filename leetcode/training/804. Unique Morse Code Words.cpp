#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (auto &word : words)
        {
            string temp = "";
            for (auto &c : word)
                temp.append(morse[c - 'a']);
            s.emplace(temp);
        }
        return s.size();
    }
};