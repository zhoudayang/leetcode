//思路：滑动窗口。两个hash map可以直接比较大小，但是要注意清除值为0的项。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size())
            return result;
        unordered_map<char, int> str1;
        unordered_map<char, int> str2;
        for (int i = 0; i < p.size(); ++i)
        {
            ++str1[s[i]];
            ++str2[p[i]];
        }
        if (str1 == str2)
            result.push_back(0);
        for (int i = p.size(); i < s.size(); ++i)
        {
            char end = s[i - p.size()];
            char begin = s[i];
            ++str1[begin];
            if (--str1[end] == 0)
            {
                str1.erase(end);
            }
            if (str1 == str2)
                result.push_back(i - p.size() + 1);
        }
        return result;
    }
};
