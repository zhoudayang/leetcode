// dp,建立 vector <unordered_map<int, int>> dp(n)，dp[i][dist]表示以字符i结尾距离为dist的字符串pair的数目。
// for i in range(1,n) for i in range(0,i), 计算字符i和字符j之间的距离，如果他们的距离超过int数的表示范围，跳过。
// 更新以i字符结尾并且距离为刚才计算得到的dist的字符串pair的数目。如果能够找到以字符j结尾并且距离为dist的字符串pair，
// 更新dp[i][dist],和最终返回的结果，都加上dp[j][dist]
class Solution {
public:
  long calculate_dist(long a, long b) {
    return a - b;
  }
  int numberOfArithmeticSlices(vector<int> &A) {
    int n = A.size();
    vector <unordered_map<int, int>> dp(n);
    int result = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        // distance between i and j
        long dist = calculate_dist(A[i], A[j]);
        // if overflow, continue
        if (dist > INT_MAX || dist < INT_MIN)
          continue;
        //以字符i结尾，距离为dist的pair的数目
        dp[i][dist] += 1;
        //以字符j结尾，距离为dist的pair的数目
        if (dp[j].find(dist) != dp[j].end()) {
          // update dp[i][dist]
          dp[i][dist] += dp[j][dist];
          // update result
          result += dp[j][dist];
        }
      }
    }
    return result;
  }
};