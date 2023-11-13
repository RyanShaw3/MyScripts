#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> threeEqualParts(vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3 != 0) {
      return {-1, -1};
    } else if (sum == 0) {
      return {0, 2};
    }
    int part = sum / 3;
    int first = 0, second = 0, third = 0, count = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 1) {
        if (count == 0) {
          first = i;
        } else if (count == part) {
          second = i;
        } else if (count == part * 2) {
          third = i;
        }
        count++;
      }
    }
    int len = (int)arr.size() - third;
    if (first + len <= second && second + len <= third) {
      int i = 0;
      while (third + i < arr.size()) {
        if (arr[first + i] != arr[second + i] ||
            arr[first + i] != arr[third + i]) {
          return {-1, -1};
        }
        i++;
      }
      return {first + len - 1, second + len};
    }
    return {-1, -1};
  }
};