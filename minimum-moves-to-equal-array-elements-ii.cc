//思路：问题等价于求需要几次move操作能将数组中的所有元素转换为数组的中位数。
class Solution{
public:
    int minMoves2(vector<int> &nums){
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int result = 0;
        while(i<j){
            result += nums[j] - nums[i];
            ++i;--j;
        }
        return result;
    }
}
