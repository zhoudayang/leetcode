/*
All you need is determine replace n with n + 1 or n - 1, when n is odd. since,

if n is even, you get no choice, just replace it with n / 2.
if n is odd, you can either add 1 or reduce 1.
If n + 1 % 4 == 0, replace n with n + 1 will short the path. Otherwise, replace n with n - 1 is always the right direction.

 */
class Solution {
 public:
  Solution() : result(0) {}
  int integerReplacement(int n) {
    if (n == 1)
      return result;
    if (n == 3)
    {
      result +=2 ;
      return result;
    }
    if (n == INT_MAX)
      return 32;
    if (n & 1) {
      result++;
      if ((n + 1) % 4 == 0) {
        integerReplacement(n + 1);
      } else {
        integerReplacement(n - 1);
      }
    }
    else {
      result++;
      integerReplacement(n >> 1);
    }
    return result;
  }
 private:
  int result;
};