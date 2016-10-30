//idea: prefix tree
class node {
 public:
  //child node represent zero
  node *zero;
  //child node represent one
  node *one;

  //constructor
  node() :
      zero(nullptr),
      one(nullptr) {
  }

  node *update(int value) {
    if (value == 1) {
      if (!one)
        one = new node();
      return one;
    } else {
      if (!zero) {
        zero = new node();
      }
      return zero;
    }
  }

};

class Solution {
 public:

  int findMaximumXOR(vector<int> &nums) {
    root = new node;
    //建树
    for (auto num:nums)
      insert(num);
    int result = 0;
    //根据xor计算的性质，找到与num xor运算最大的那个前缀
    for (auto num:nums)
      result = max(findMax(num), result);
    return result;
  }
 private:
  int findMax(int num) {
    int result = 0;
    node *cur = root;
    for (int pos = 31; pos >= 0; --pos) {
      int digit = (num >> pos) & 1;
      if (digit == 1) {
        if (cur->zero) {
          result = result | (1 << pos);
          cur = cur->zero;
        } else
          cur = cur->one;
      } else {
        if (cur->one) {
          result = result | (1 << pos);
          cur = cur->one;
        } else
          cur = cur->zero;
      }
    }
    return result;
  }
  void insert(int val) {
    node *cur = root;
    for (int pos = 31; pos >= 0; --pos) {
      int digit = (val >> pos) & 1;
      cur = cur->update(digit);
    }
  }
 private:
  node *root;
};