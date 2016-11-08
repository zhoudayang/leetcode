/*
The simplest approach consists of trying to find out every possible square of 1’s that can be formed from within the matrix. The question now is – how to go for it?

We use a variable to contain the size of the largest square found so far and another variable to store the size of the current, both initialized to 0. Starting from the left uppermost point in the matrix, we search for a 1. No operation needs to be done for a 0. Whenever a 1 is found, we try to find out the largest square that can be formed including that 1. For this, we move diagonally (right and downwards), i.e. we increment the row index and column index temporarily and then check whether all the elements of that row and column are 1 or not. If all the elements happen to be 1, we move diagonally further as previously. If even one element turns out to be 0, we stop this diagonal movement and update the size of the largest square. Now we, continue the traversal of the matrix from the element next to the initial 1 found, till all the elements of the matrix have been traversed.


 */
class Solution {
 public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = m > 0 ? matrix[0].size() : 0;
    int max_len = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1') {
          int len = 1;
          bool flag = true;
          while (flag && i + len < m && j + len < n) {
            for (int k = i; k <= i + len; ++k) {
              //检查多出来的一列
              if (matrix[k][j + len] == '0') {
                flag = false;
                break;
              }
            }
            for (int k = j; k <= j + len; ++k) {
              //检查多出来的一行
              if (matrix[i + len][k] == '0') {
                flag = false;
                break;
              }
            }
            if(flag)
              ++len;
          }
          max_len = max(len, max_len);
        }
      }
    }
    return max_len * max_len;
  }
};