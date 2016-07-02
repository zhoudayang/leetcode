#include<iostream>
#include<vector>

using namespace std;
//思路:dp 首先将envelope按照width从小到大进行排序,如果有两个envelope的width相同,那么按照height进行排序
//height较小的envelope排在前面。
//设dp[i]表示第i个信封最多能够盛放的envelope的个数。
//则状态转移方程为:dp[i] = max(dp[i],dp[j]+1) (if envelopes[i].l > envelopes[j].l and envelopes[i].r > envelopes[j].r)
//j <i 。最终要求的值是dp数组中的最大值
class Solution {
private:
    static bool cmp(pair<int, int> l, pair<int, int> r) {
        if (l.first == r.first)
            return l.second < r.second;
        return l.first < r.first;
    }

public:
    int maxEnvelopes(vector<pair<int, int>> &envelopes) {
        int size = envelopes.size();
        if (size == 0)
            return 0;
        vector<int> dp(size, 1);
        sort(envelopes.begin(), envelopes.end(), cmp);
        int mx = 1;
        for (int i = 1; i < size; i++) {
            for (int j = i - 1; j > -1; j--) {
                if (envelopes[i].first > envelopes[j].first and envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(mx, dp[i]);
                }
            }
        }
        return mx;
    }
};

int main() {


    return 0;
}