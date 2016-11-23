//使用以下3条性质进行解题：
//完美矩形的面积等于所有矩形面积之和
//完美矩形的坐标由min_x,min_y,max_x,max_y确定
//完美矩形有4个顶点。其他在小矩形中出现而不是完美矩形的顶点都是成对出现。

class Solution {
 public:
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    int min_x = INT_MAX;
    int min_y = INT_MAX;
    int max_x = INT_MIN;
    int max_y = INT_MIN;
    unordered_set<string> set;
    int area = 0;
    for (auto rect:rectangles) {
      min_x = min(min_x, rect[0]);
      min_y = min(min_y, rect[1]);
      max_x = max(max_x, rect[2]);
      max_y = max(max_y, rect[3]);
      area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
      string pos[4];
      pos[0] = to_string(rect[0]) + "," + to_string(rect[1]);
      pos[1] = to_string(rect[0]) + "," + to_string(rect[3]);
      pos[2] = to_string(rect[2]) + "," + to_string(rect[3]);
      pos[3] = to_string(rect[2]) + "," + to_string(rect[1]);
      for (auto p:pos) {
        if (!set.insert(p).second)
          set.erase(p);
      }
    }
    string a = to_string(min_x) + "," + to_string(max_y);
    string b = to_string(min_x) + "," + to_string(min_y);
    string c = to_string(max_x) + "," + to_string(max_y);
    string d = to_string(max_x) + "," + to_string(min_y);
    if (set.size() != 4 || !set.count(a) || !set.count(b) || !set.count(c) || !set.count(d))
      return false;
    return area == (max_x - min_x) * (max_y - min_y);
  }
};
