/*
	求最大公约数GCD（Greatest Common Divisor)。
	如果x与y互质（最大公约数为1），则容量范围[1, max(x, y)]之内的任意整数体积均可以通过适当的操作得到。
	否则，记x与y的最大公约数为gcd，则可以获得的容量z只能为gcd的整数倍，且z <= max(x, y)。
*/

class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    if (x + y < z)
      return false;
    if (x == z || x + y == z || y == z)
      return true;
    return (z % gcd(x, y)) == 0;
  }
 private:
  int gcd(int x, int y) {
    while (y != 0) {
      int temp = y;
      y = x % y;
      x = temp;
    }
    return x;
  }
};
