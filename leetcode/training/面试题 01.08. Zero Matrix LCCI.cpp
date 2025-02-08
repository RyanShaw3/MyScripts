#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    bool flag = false;
    vector<int> mark(m, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          mark[j] = 0;
          flag = true;
        }
      }
      if (flag) {
        for (int k = 0; k < m; k++) {
          matrix[i][k] = 0;
        }
        flag = false;
      }
    }
    for (int j = 0; j < m; j++) {
      if (mark[j] == 0) {
        for (int i = 0; i < n; i++) {
          matrix[i][j] = 0;
        }
      }
    }
    return;
  }
};