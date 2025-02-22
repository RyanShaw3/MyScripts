#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int getKthMagicNumber(int k) {
    vector<int> nums(k);
    nums[0] = 1;
    int p3 = 0, p5 = 0, p7 = 0;
    for (int i = 1; i < k; i++) {
      nums[i] = min(nums[p3] * 3, min(nums[p5] * 5, nums[p7] * 7));
      if (nums[i] == nums[p3] * 3) {
        p3++;
      }
      if (nums[i] == nums[p5] * 5) {
        p5++;
      }
      if (nums[i] == nums[p7] * 7) {
        p7++;
      }
    }
    return nums[k - 1];
  }
};