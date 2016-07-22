/*
The basic idea is to use a multiset to save sum, where sum at i = nums[0]+...+ nums[i].
 At each i, only those sum[j] that satisfies lower=< sum[i]-sum[j]<= upper 
 can generate a valid range[j,i]. so we only need to calculate how many j (0=< j< i)
 satisfy sum[i]-upper=< sum[j]<=-sum[i]-lower. 
 The STL multiset can take care of sort and find upper_bound, lower_bound j.
 Since the multiset is usually implemented with Red-black tree, 
 so those operations should have complexity of O(logN). 
 So in total, the complexity is O(NlogN) (except the distance part). 

 */
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> sums;
        sums.insert(0);
        int res =0;
        long long sum=0;
        int size = nums.size();
        for(int i=0;i<size;i++){
            sum+=nums[i];
            res+= distance(sums.lower_bound(sum-upper),sums.upper_bound(sum-lower));
            sums.insert(sum);
        }
        return res;
    }
};
//因为有效的range_sum的个数为满足条件的区间长度加1，所以其中右下标的求解使用了函数upper_bound。
//因而，上述代码其实和下述代码是一致的：
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> sums;
        sums.insert(0);
        int res =0;
        long long sum=0;
        int size = nums.size();
        for(int i=0;i<size;i++){
            sum+=nums[i];
            auto right = sums.lower_bound(sum-lower);
            while(right!=sums.end() and *right==(sum-lower))
                right++;
            res+= distance(sums.lower_bound(sum-upper),right);
            sums.insert(sum);
        }
        return res;
    }
};