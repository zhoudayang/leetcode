/*
枚举点i(x1, y1)，计算点i到各点j(x2, y2)的距离，并分类计数

利用排列组合知识，从每一类距离中挑选2个点的排列数 A(n, 2) = n * (n - 1)

将上述结果累加即为最终答案
 */
class Solution {
 public:
  int numberOfBoomerangs(vector<pair<int, int>> &points) {
    int result = 0;
    for (int i = 0; i < points.size(); ++i) {
      unordered_map<uint64_t, int> dis;
      for (int j = 0; j < points.size(); j++) {
        if (i == j)
          continue;
        int dy = points[j].second - points[i].second;
        int dx = points[j].first - points[i].first;
        ++dis[dx * dx + dy * dy];
      }
      for (auto &pair:dis) {
        int number = pair.second;
        if (number > 1)
          result += number * (number - 1);
      }
    }
    return result;
  }
};