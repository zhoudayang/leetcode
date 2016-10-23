//统计当前滑窗内最多的字母，窗口宽度 - 最多字母数量 <= k，就可以继续尝试向右扩大窗口,从左边缩小窗口l++。  
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        if (s.empty())
            return 0;
        int count[26] = {};
        int result = 1;
        ++count[s[0]-'A'];
        int l = 0;
        int r = 1;
        int max_value = 1;
        for (; r<s.size(); ++r)
        {
            max_value = max(max_value, ++count[s[r]-'A']);
            if (r-l+1-max_value>k)
                --count[s[l++]-'A'];
            else
                result = max(result, r-l+1);
        }
        return result;

    }
};
