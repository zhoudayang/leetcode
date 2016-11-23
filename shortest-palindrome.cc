//基本的思路时找出从位置0开始的最长回文字符串，然后在字符串开头加上调转字符串，且长度为原字符串长度减去最长回文字符串的长度。但是此法无法执行，超时！
//为此可以把原问题转换为求一个字符串的最长前缀后缀。
//我们需要添加字符之后最短的回文数。为此构建一个字符串，设原来的字符串为s，将s字符串的转置字符串设为reverse_str,
//构建字符串s+"#"+reverse_str,求新字符串的最长前缀后缀，设其长度为common_len。最后，只需要在原字符串前面添加reverse_str的前面
//s.size()-common_len个字符即可。
//举例子：
/*
  origin_str : aacecaaa
  connection_str: aacecaaa#aaacecaa
  max_fix_str : aacecaa
  所以需要在orgin_str前面添加a字符
*/
class Solution{
public:
    string shortestPalindrome(string s){
        string reverse_str = string(s.rbegin(),s.rend());
        string connection_str = s + "#" + reverse_str;
        vector<int> common_len(connection_str.size(),0);
        int k = 0;
        for(int i=1;i<connection_str.size();i++){
            while(connection[i]!=connection[k] and k > 0 ){
                k = common_len[k-1];
            }
            if(connection[k] == connection[i]){
                common_len[i] = ++k;
            }
            else
                common_len[i] = 0;
        }
        int common_length = common_len.back();
        return reverse_str.substr(0,s.size()-common_length) + s;
    }
}
