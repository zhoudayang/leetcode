//思路：多数投票算法
/*
    The essential concepts is you keep a counter for the majority number X. If you find a number Y that is not X, the current counter should deduce 1. The reason is that if there is 5 X and 4 Y, there would be one (5-4) more X than Y. This could be explained as "4 X being paired out by 4 Y".

    And since the requirement is finding the majority for more than ceiling of [n/3], the answer would be less than or equal to two numbers.
    So we can modify the algorithm to maintain two counters for two majorities.
    参考：http://www.jianshu.com/p/dfd676b71ef0
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x=0,y=0,cx=0,cy=0;
        for(auto num:nums){
            if(num==x)
                cx++;
            else if(num==y)
                cy++;
            else if(cx==0){
                x=num;
                cx=1;
            }
            else if(cy==0){
                y=num;
                cy=1;
            }
            else{
                cx--;
                cy--;
            }
        }
        vector<int> ret;
        cx=cy=0;
        for(auto num:nums){
            if(x==num)
                cx++;
            else if(y==num)
                cy++;
        }
        int size = nums.size()/3;
        if(cx>size)
            ret.push_back(x);
        if(cy>size)
            ret.push_back(y);
        return ret;
    }
    
};