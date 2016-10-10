//思路：从字符串末尾往前遍历，仿照加法运算进行处理，注意如果字符串越界以零代替。另外最后要处理一下进位。
class Solution {
public:
    string addString(string num1, string num2) {
        string res;
        int size1 = num1.size();
        int size2 = num2.size();
        int advance = 0;
        for (int i = size1 - 1, j = size2 - 1; i >= 0 || j >= 0; --i, --j)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int sum = n1 + n2 + advance;
            int cur = sum % 10;
            advance = sum / 10;
            res.push_back((cur + '0'));
        }
        if (advance != 0)
        {
            res.push_back(advance + '0');
        }
        return string(res.rbegin(), res.rend());
    }
};
