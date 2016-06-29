#include<iostream>
#include<vector>

using namespace std;
/*
    题意：给定一个数组，求其中的一个最大子集，要求该子集中任意的两个元素满足 x % y ==0 或者 y % x==0

    思路：其实和求最大上升子序列LIS差不多，只不过这题要求输出序列而已。

    先把数组排好序。首先要明确，若a<b且b%a==0 ,  b <c 且 c%b==0那么必然有c%a==0

    我们设dp[i] 为最大的子集的长度，更新的时候只需要保存上一个的下标即可。
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        if (nums.empty())
            return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> index(n, -1);
        int ret = 1;
        int max_index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    index[i] = j;
                }
                if (dp[i] > ret) {
                    ret = dp[i];
                    max_index = i;
                }
            }
        }
        vector<int> results;
        for (int i = max_index; i != -1; i = index[i])
            results.push_back(nums[i]);
        return results;
    }
};

int main() {


    return 0;
}