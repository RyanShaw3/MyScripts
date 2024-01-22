#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> ump;
    for (auto &cpdomain : cpdomains) {
      int space = cpdomain.find(' ');
      int count = stoi(cpdomain.substr(0, space));
      string domain = cpdomain.substr(space + 1);
      ump[domain] += count;
      for (int i = 0; i < domain.size(); i++) {
        if (domain[i] == '.') {
          ump[domain.substr(i + 1)] += count;
        }
      }
    }
    vector<string> ans;
    for (auto &&[k, v] : ump) {
      ans.emplace_back(to_string(v) + " " + k);
    }
    return ans;
  }
};