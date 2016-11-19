//可以将问题分解为从num1和num2数组中取出共计k个数，并且这k个数按照原有的顺序进行排序，并且这些数字组成的数最大。maxVector函数找到给定数组nums中长度为len且最大的子数组，merge函数合并num1和num2，使得他们组成的数最大。
class Solution {
public:
  vector<int> maxNumber(vector<int> &num1, vector<int> &num2, int k) {
    int m = num1.size();
    int n = num2.size();
    vector<int> result;
    for (int i = max(0, k - n); i <= min(m, k); ++i) {
      result = max(result, merge(maxVector(num1, i), maxVector(num2, k - i)));
    }
    return result;
  }
  vector<int> maxVector(vector<int> nums, int len) {
    vector<int> result;
    int drop = nums.size() - len;
    for (int num:nums) {
      while (result.size() && drop && result.back() < num) {
        result.pop_back();
        --drop;
      }
      result.push_back(num);
    }
    result.resize(len);
    return result;
  }
  vector<int> merge(vector<int> num1, vector<int> num2) {
    vector<int> result;
    while (num1.size() or num2.size()) {
      vector<int> &tmp = num1 > num2 ? num1 : num2;
      result.push_back(tmp.front());
      tmp.erase(tmp.begin());
    }
    return result;
  }
};
