//思路：统计magazine中每个字符的出现次数，对于ransomNode中的每个字符，相应减去magazine统计的对应字符的出现次数，如果出现减去后
//得到的值为负数，那么说明magazine中的字符不足够用于组成ransomNode，返回false。最终ransomNode中的每个字符都能够满足条件，返回true。    
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charcters;
        for (auto ch:magazine)
            charcters[ch] += 1;
        for (auto ch:ransomNote) {
            if (--charcters[ch] < 0)
                return false;
        }
        return true;
    }
};