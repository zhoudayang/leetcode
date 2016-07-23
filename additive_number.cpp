/*
use a helper function to add two strings.

Choose first two number then recursively check.

Note that the length of first two numbers can't be longer than half of the initial string, so the two loops in the first function will end when i>num.size()/2 and j>(num.size()-i)/2, this will actually save a lot of time.

Update the case of heading 0s
e.g. "100010" should return false


 */
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int size = num.size();
        for (int i = 1; i <= size / 2; i++)
            for (int j = 1; j <= (size - i) / 2; j++)
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;
        return false;
    }

    string add(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res;
        while (i >= 0 || j >= 0) {
            int sum = carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            res.push_back('0' + carry);
        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string num1, string num2, string num) {
        if (num1.size() > 1 and num1[0] == '0' || num2.size() > 1 and num2[0] == '0')
            return false;
        string sum = add(num1, num2);
        if (sum == num)
            return true;
        if (sum.size() >= num.size() || sum.compare(num.substr(0, sum.size())) != 0)
            return false;
        return check(num2, sum, num.substr(sum.size()));
    }
};