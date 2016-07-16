#include<iostream>

using namespace std;


//思路：将加法分为两步，加法和进位，
// 将每次进位的结果和加法的结果再递归调用getSum函数求出和，直至进位为0，表示加法完成，返回a作为结果。
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)//如果没有进位,运算完成
            return a;
        int add = a ^b;//完成第一步的加法
        int carry = (a & b) << 1;//完成第二步进位并左移
        return getSum(add, carry);
    }
};

int main() {
    Solution *s = new Solution();
    cout<<s->getSum(1,2)<<endl;
    return 0;
}
