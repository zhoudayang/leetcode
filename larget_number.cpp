//思路：排序
/*
    重点在于理解排序规则：详见匿名函数：[](string &a,string &b){return a+b>b+a;}
    按连接后得到的字符串的大小从大到小进行排序，连接排序之后的字符串就得到结果
    注意输入的数字都是非负数，所以如果遇到输入的数字全是0，直接返回0即可。这种情况可以通过判断数组中的最大数是否为0得到。
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        int max_value = INT_MIN;
        for(auto num:nums){
            max_value = max(max_value,num);
            strs.push_back(to_string(num));
        }
        if(max_value==0)
            return "0";
        sort(strs.begin(),strs.end(),[](string &a,string &b){
            return a+b>b+a;
        });
        string result ="";
        for(string str:strs)
            result+=str;
        return result;
    }
};