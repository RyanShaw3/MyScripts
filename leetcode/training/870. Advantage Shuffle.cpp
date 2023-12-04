#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    int n = nums1.size();
    vector<int> id2(n);
    for (int i = 0; i < n; i++) {
      id2[i] = i;
    }
    sort(id2.begin(), id2.end(),
         [&](int i, int j) { return nums2[i] < nums2[j]; });
    vector<int> ans(n);
    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
      if (nums1[i] > nums2[id2[left]]) {
        ans[id2[left]] = nums1[i];
        left++;
      } else {
        ans[id2[right]] = nums1[i];
        right--;
      }
    }
    return ans;
  }
};