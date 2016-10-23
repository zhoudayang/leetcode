//使用set存储前3大的数。set帮我们进行了去重。在插入过程中保证set的大小不超过3。最后，若set的大小等于3，返回第三大的数，即set的开头，否则返回最大的数，即set的末尾。
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for(int num:nums){
            top3.insert(num);
            if(top3.size()>3){
                top3.erase(top3.begin());
            }
        }
        return top3.size() == 3? *top3.begin(): *top3.rbegin();
    }
};