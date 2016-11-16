/*
题目中给足了提示，首先告诉我们要3个一组的进行处理，而且题目中限定了输入数字范围为0到231 - 1之间，最高只能到billion位，3个一组也只需处理四组即可，那么我们需要些一个处理三个一组数字的函数，我们需要把1到19的英文单词都列出来，放到一个数组里，还要把20,30，... 到90的英文单词列出来放到另一个数组里，然后我们需要用写技巧，比如一个三位数n，百位数表示为n/100，后两位数一起表示为n%100，十位数表示为n%100/10，个位数表示为n%10，然后我们看后两位数是否小于20，小于的话直接从数组中取出单词，如果大于等于20的话，则分别将十位和个位数字的单词从两个数组中取出来。然后再来处理百位上的数字，还要记得加上Hundred。主函数中最多调用四次这个帮助函数，然后中间要插入"Thousand", "Million", "Billion"到对应的位置，最后check一下末尾是否有空格，把空格都删掉，返回的时候检查下输入是否为0，是的话要返回'Zero'。
*/
class Solution {
 public:
  string numberToWords(int num) {
    string res = convertHundred(num % 1000);
    static vector<string> v{"Thousand", "Million", "Billion"};
    for (int i = 0; i < 3; ++i) {
      num /= 1000;
      res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
    }
    while ( res.back() ==' ')
      res.pop_back();
    if(res.empty())
      return "Zero";
    return res;
  }
 private:
  string convertHundred(int num) {
    static vector<string> v1
        {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
         "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    static vector<string> v2{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    int a = num / 100;
    int b = num % 100;
    int c = num % 10;
    // b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
    string res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
    if (a)
      res = v1[a] + " Hundred" + (b ? " " + res : "");
    return res;
  }
};
