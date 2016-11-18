//思路：满足条件的子串长度必须可以整除整个字符串的长度。设满足条件的子串长度为len,那么必有原字符串和将原字符串向左移动len位置的字符串内容完全一致。
class Solution {
 public:
  bool repeatedSubstringPattern(string str) {
    int size = str.size();
    for (int i = 1; i <= size/2; ++i) {
      string nextStr = left_shift_string(str, i);
      if (nextStr==str) {
        return true;
      }
    }
    return false;
  }
 private:
  string left_shift_string(string &str, int l) {
    string ret(str.substr(l));
    ret += str.substr(0, l);
    return ret;
  }
};

//实际上，上述代码和下面的代码原理完全一致，并且下面的代码更加运行起来更加快捷。
class Solution {
 public:
  bool repeatedSubstringPattern(string str) {
    int size = str.size();
    for (int i = 1; i <= size/2; ++i) {
      if (str.substr(i)==str.substr(0, size - i))
        return true;
    }
    return false;
  }

};
