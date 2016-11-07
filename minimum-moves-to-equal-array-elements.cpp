// 一次移动将n - 1个元素加1，等价于将剩下的1个元素减1。
// 因此累加数组中各元素与最小值之差即可。
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = INT_MAX,sum = 0;
        for(int i =0;i<nums.size();++i){
            min_num = nums[i] < min_num ? nums[i]: min_num;
            sum += nums[i];
        }
        return sum - nums.size()*min_num;
    }
};