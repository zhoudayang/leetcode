//使用greedy，遍历字符，将其加入res。对于每一个字符，如果其小于res的尾部元素且当前去除的字符个数小于k，将res末尾的字符除去。并且将该字符push到字符串
//res的末尾。最后保证res的长度不超过keep=num.size()-k,若超过，除去末尾超出长度的字符串，并且除去前缀0。最终得到的res结果如果为空，返回0，否则返回res。
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int n = num.size();
        int keep = n - k;
        for (auto ch:num)
        {
            while (res.size() && k && res.back() > ch)
            {
                res.pop_back();
                --k;
            }
            res.push_back(ch);
        }
        while (res.size() && res.front() == '0')
            res.erase(res.begin());
        return res.empty() ? "0":res;
    }
};