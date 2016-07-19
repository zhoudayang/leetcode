class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        if (len == 0)
            return 0;
        int top;
//       初始设置sign为 +,设置num为0
        char sign = '+';
        int num = 0;
//        使用栈存储中间计算结果
        stack<int> nums;
        for (int i = 0; i < len; i++) {
            char ch = s[i];
//            如果sign是数字符号,那么更新num
            if (isdigit(ch))
                num = num * 10 + ch - '0';
//            如果num是运算符号或者是最后一个字符
            if (!isdigit(ch) && ch != ' ' or i == len - 1) {
//                根据上一个出现的运算符确定这次的计算方式
                switch (sign) {
                    case '+':// add
                        nums.push(num);
                        break;
                    case '-':// minus
                        nums.push(-num);
                        break;
                    case '*':// multiply
                        top = nums.top();
                        nums.pop();
                        nums.push(top * num);
                        break;
                    case '/': // divide
                        top = nums.top();
                        nums.pop();
                        nums.push(top / num);
                        break;
                }
                //set sign
                sign = ch;
                // reset num to zero
                num = 0;
            }
        }
        // add all items in stack
        int ret = 0;
        while (!nums.empty()) {
            ret += nums.top();
            nums.pop();
        }
        return ret;
    }
};