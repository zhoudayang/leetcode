/*
    For each number x in range[i~j]
    we do: result_when_pick_x = x + max{DP([i~x-1]), DP([x+1, j])}
    --> // the max means whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
    then we get DP([i~j]) = min{xi, ... ,xj}
    --> // this min makes sure that you are minimizing your cost.
 */
class Solution {
public:
    int help(vector<vector<int>> &dp, int l, int r) {
        if (l >= r)
            return 0;
        if (dp[l][r])
            return dp[l][r];
        dp[l][r] = INT_MAX;
        for (int i = l; i <= r; i++) {
            dp[l][r] = min(dp[l][r], i + max(help(dp, l, i - 1), help(dp,i+1,r)));
        }
        return dp[l][r];
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return help(dp, 1, n);
    }
};
