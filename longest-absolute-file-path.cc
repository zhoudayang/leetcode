//思路：遍历字符串，通过判断文件或者文件夹名前面有几个'\t'判断当前是多少级目录。使用map存放各级目录对应的目录名长度。取出当前遍历得到的文件或者文件夹名称，若
//判定为文件名，则尝试更新最大绝对路径长。若为文件夹名，则更新当前层级对应的绝对路径长度。初始设置0级目录的长度为０(当然成立)
class Solution {
 public:
  int lengthLongestPath(string input) {
    int result = 0;
    unordered_map<int, int> level_count;
    level_count[0] = 0;
    int len = input.size();
    for (int i = 0; i < len; ++i) {
      //the file or directory name size
      int size = 0;
      //level注明是多少级目录
      int level = 1;
      bool isFile = false;
      while (input[i]=='\t') {
        ++level;
        ++i;
      }
      while (input[i]!='\n' and i < len) {
        if (input[i]=='.')
          isFile = true;
        ++size;
        ++i;
      }
      if (isFile) {
        result = max(result, level_count[level - 1] + size);
      } else {
        level_count[level] = level_count[level - 1] + size + 1; // 1  for '/'
      }
    }
    return result;
  }
};
