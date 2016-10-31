//simple math problem, you can also overcome it by calculate directly
class Solution {
 public:
  int arrangeCoins(int n) {
    int cur = 1;
    long sum = 0;
    for (int cur = 1;; ++cur) {
      sum += cur;
      if (sum == n) {
        return cur;
      } else if (sum > n) {
        return cur - 1;
      }
    }
  }
};