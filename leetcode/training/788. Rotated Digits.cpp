#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int rotatedDigits(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      string num = to_string(i);
      bool no2569 = true, no347 = true;
      for (auto c : num) {
        if (c == '3' || c == '4' || c == '7') {
          no347 = false;
          break;
        } else if (c == '2' || c == '5' || c == '6' || c == '9') {
          no2569 = false;
        }
      }
      if (no347 && !no2569) {
        ans++;
      }
    }
    return ans;
  }
};