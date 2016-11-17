/*
	思路：首先使用hash_map统计数组A，B 以及数组C，D的和的数目。然后遍历数组A，B所有两两元素之和sum，在另一个hash_map中寻找-sum，若找到了，则更新result。请注意更新result += 为两个map中对应和出现次数的乘积。
*/
class Solution {
 public:
  void fill(vector<int> &A, vector<int> &B, unordered_map<int, int> &m) {
    int n = A.size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ++m[A[i] + B[j]];
  }

  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
    unordered_map<int, int> sum1;
    unordered_map<int, int> sum2;
    fill(A, B, sum1);
    fill(C, D, sum2);
    int result = 0;
    for (auto it = sum1.begin(); it!=sum1.end(); ++it) {
      int sum = it->first;
      auto iter = sum2.find(-sum);
      if (iter!=sum2.end())
        result += it->second*iter->second;
    }
    return result;
  }
};
