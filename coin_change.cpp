#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        //sort coins
        sort(coins.begin(), coins.end());
        //dp[i] show the smallest number of coins that need to accumulate  to i
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i<=amount; ++i)
        {
            for (auto coin:coins)
            {
                int begin = i-coin;
                //if the last begin index is invalid, return directly
                if (begin<0)
                    break;
                //if the last begin index is valid
                if (dp[begin]!=INT_MAX)
                {
                    //update dp[i]
                    dp[i] = min(dp[i], dp[begin]+1);
                }
            }
        }
        return dp[amount]!=INT_MAX ? dp[amount] : -1;
    }
};

int main()
{
    Solution s;
    vector<int> coins {1,2,5};
    cout<<s.coinChange(coins,11)<<endl;

    return 0;
}
