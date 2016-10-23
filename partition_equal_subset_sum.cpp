//思路：如果需要满足题设条件，那么数组中所有数之和必定为偶数，只要我们能够在数组中找到一个子数组和为sum/2即可。
//初始化dp[sum/2],dp[0]=true,数组中其他元素的值为false。遍历数组nums,dp[i]为true只有当dp[i]||dp[i-num]为true。
//请注意i的取值范围是[num,target]，我们只考虑在数组中找到和为target的子数组。
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (auto num:nums)
        {
            for (int i = target; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
