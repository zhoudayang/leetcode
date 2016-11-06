//solution1: cache row 
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) {
    int row = matrix.size();
    if(row==0)
        return;
    int col = matrix[0].size();
    if(col==0)
        return;
    for(int i=0;i<row;++i){
      vector<int> temp(col+1,0);
      //temp 中的每一项temp[i] 记录了 [0->i) 列的元素之和 (列的下标从0开始)
      for(int j=0;j<col;++j){
        temp[j+1] = temp[j] + matrix[i][j];
      }
      dp.push_back(temp);
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for(int row = row1;row<=row2;++row){
      sum+=dp[row][col2+1] - dp[row][col1];
    }
    return sum;
  }
 private:
  vector<vector<int>> dp;
};
//Solution2: Caching Smarter
/*
Construct a 2D array sums[row+1][col+1]

(notice: we add additional blank row sums[0][col+1]={0} and blank column sums[row+1][0]={0} to remove the edge case checking), so, we can have the following definition

sums[i+1][j+1] represents the sum of area from matrix[0][0] to matrix[i][j]

To calculate sums, the ideas as below

+-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
|     | |       |     |        |     |     |     |         |     |     |        |
|     | |       |     |        |     |     |     |         |     |     |        |
+-----+-+       |     +--------+     |     |     |         |     +-----+        |
|     | |       |  =  |              |  +  |     |         |  -  |              |
+-----+-+       |     |              |     +-----+         |     |              |
|               |     |              |     |               |     |              |
|               |     |              |     |               |     |              |
+---------------+     +--------------+     +---------------+     +--------------+

   sums[i][j]      =    sums[i-1][j]    +     sums[i][j-1]    -   sums[i-1][j-1]   +  

                        matrix[i-1][j-1]
So, we use the same idea to find the specific area's sum.

+---------------+   +--------------+   +---------------+   +--------------+   +--------------+
|               |   |         |    |   |   |           |   |         |    |   |   |          |
|   (r1,c1)     |   |         |    |   |   |           |   |         |    |   |   |          |
|   +------+    |   |         |    |   |   |           |   +---------+    |   +---+          |
|   |      |    | = |         |    | - |   |           | - |      (r1,c2) | + |   (r1,c1)    |
|   |      |    |   |         |    |   |   |           |   |              |   |              |
|   +------+    |   +---------+    |   +---+           |   |              |   |              |
|        (r2,c2)|   |       (r2,c2)|   |   (r2,c1)     |   |              |   |              |
+---------------+   +--------------+   +---------------+   +--------------+   +--------------+

*/
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) {
    int row,col;
    if((row = matrix.size()) == 0 || (col = matrix[0].size())==0)
      return;
    for(int i = 0;i<= row;++i)
      dp.push_back(vector<int>(col+1,0));
    for(int r =0;r<row;++r){
      for(int c = 0;c<col;++c){
        dp[r+1][c+1] = dp[r+1][c] + dp[r][c+1] +matrix[r][c] -dp[r][c];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return dp[row2+1][col2+1] -dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
  }
 private:
  vector<vector<int>> dp;
};

//solution2: 