class Solution {
public:
    //use map to memorize middle results
    map<pair<int, int>, bool> dp;

    //pos represent begin of the jump, k represent the last jump gap
    bool canCross(vector<int> &stones, int pos = 0, int k = 0) {
        auto key = make_pair(pos, k);
        //if solve the same middle problem, return the memorize result
        if (dp.count(key))
            return dp[key];
        //try to jump to next stone
        for (int i = pos + 1; i < stones.size(); ++i)
        {
            int gap = stones[i] - stones[pos];
            //in this case, try to jump next higher stone, pass this stone
            if (gap < k - 1)
                continue;
            //if the lower stone that height is higher than k+1, the frog cannot cross the river , set dp and return false
            else if (gap > k + 1)
            {
                dp[key] = false;
                return false;
            }
            //if can cross the river, set dp and return true
            else if (canCross(stones, i, gap))
            {
                dp[key] = true;
                return true;
            }
        }
        //if pos is the end of the river return true, else return false, memorize the result
        dp[key] == (pos == stones.size() - 1);
        return dp[key];
    }
};