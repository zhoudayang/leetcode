//这一题的意思是：水由大陆往低处流，求能够同时到达左上角和右下角的两个大洋的大陆的位置坐标。可以采用dfs的思路，从大洋边缘往大陆进行遍历，
//若当前大陆坐标比之前的坐标更高，表明当前位置的能够流到上一坐标。分别统计能够到达两个大洋的大陆坐标，同时能够到达这两个大洋的坐标即为所求。
class Solution {
 public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
    int m, n;
    if ((m = matrix.size()) == 0 or (n = matrix[0].size()) == 0)
      return {};
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      helper(matrix, pacific, i, 0, INT_MIN);
      helper(matrix, atlantic, i, n - 1, INT_MIN);
    }
    for (int i = 0; i < n; i++) {
      helper(matrix, pacific, 0, i, INT_MIN);
      helper(matrix, atlantic, m - 1, i, INT_MIN);
    }
    vector<pair<int, int>> results;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (atlantic[i][j] and pacific[i][j])
          results.push_back(make_pair(i, j));
      }
    }
    return results;
  }
  void helper(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int pre) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (i < 0 or i >= m or j < 0 or j >= n)
      return;
    //从高处往海里流
    if (visited[i][j] or matrix[i][j] < pre)
      return;
    visited[i][j] = true;
    pre = matrix[i][j];
    helper(matrix, visited, i - 1, j, pre);
    helper(matrix, visited, i + 1, j, pre);
    helper(matrix, visited, i, j + 1, pre);
    helper(matrix, visited, i, j - 1, pre);
  }

};
