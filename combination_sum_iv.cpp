/*
	首先将数组nums进行排序，然后初始化数组dp，dp[i]表示和为i的组合数目接下来从1到target+1进行循环，在循环内部遍历数组nums，如果当前遍历的数num大于i，之后的数也会大于i，结束内部循环。
	如果num正好等于i，就可以由这个num一个数组成一个序列，相加得到i，所以dp[i]+=1,
	剩余的情况是num<i,这种情况下，问题转换为找到一个子序列相加和为i-num,这正好是dp[i-num],
	而且因为i-num小于i，dp[i-num]已经确定了，所以dp[i]+=dp[i-num]。
	这样整个循环结束之后，dp[target]就是target对应的序列数目。
 */
class Solution{
public:
    int combinationSum4(vector<int>&nums,int target){
	int size = nums.size();
	sort(nums.begin(),nums.end());
	vector<int> dp(target+1,0);
	for(int i=1;i<dp.size();i++){
	    for(auto num:nums){
		if(num>i)
		    break;
		if(num==i)
		    dp[i]+=1;
		else 
		    dp[i]+=dp[i-num];
	    }	
	}
	return dp[target];
    }
}
