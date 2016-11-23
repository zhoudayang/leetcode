//使用数组palindrome_note记录字符串中子串的回文情况：palindrome_note[i][j] = true 说明i..j为回文字符串。
//设立状态转移数组dp[s.length()+1],其中dp[i]表示字符串i..n的最小分割数目
//则状态转移方程为：dp[i] = min(dp[i],dp[j+1]+1) 当字符串i..j为回文字符串的时候，有此方程成立。dp[j+1]对应字符串j+1的最小分割数
//若s[i]==s[j]，且i..j的长度不超过2，很明显i..j为回文字符串，否则当s[i]==s[j]且i+1...j-1为回文字符串时，i...j为回文字符串
class Solution {
 public:
  int minCut(string s) {
    int len = s.length();
    vector<int> dp(len+1);
    for(int i=0;i<=len;i++)
      dp[i] = len-1 - i;
    vector<vector<bool>> palindrome_note(len,vector<bool>(len,false));
    for(int i = len-1;i>=0;--i){
      for(int j=i;j<len;++j){
        if(s[i]==s[j] and ((j-i)<2 or palindrome_note[i+1][j-1])){
          palindrome_note[i][j] = true;
          dp[i] = min(dp[i],dp[j+1] +1);
        }
      }
    }
    return dp.front();
  }
};
