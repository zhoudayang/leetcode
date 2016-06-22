#include<iostream>
#include<vector>

using namespace std;

/*
最初的想法:
    既然最多只能完成两笔交易，而且交易之间没有重叠，那么就divide and conquer。
设i从0到n-1，那么针对每一个i，看看在prices的子序列[0,…,i][i,…,n-1]上分别取得的最大利润（第一题）即可。
这样初步一算，时间复杂度是O(n^2)。

改进：
    改进的方法就是动态规划了，那就是第一步扫描，先计算出子序列[0,…,i]中的最大利润，用一个数组保存下来，那么时间是O(n)。
第二步是逆向扫描，计算子序列[i,…,n-1]上的最大利润，这一步同时就能结合上一步的结果计算最终的最大利润了，这一步也是O(n)。
所以最后算法的复杂度就是O(n)的。
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (size < 2)
            return 0;
        int lowest = prices.front();
        int maxProfit = 0;
        vector<int> maxWithEnd{0};
        for (int i = 1; i < size; i++) {
            maxProfit = max(maxProfit, prices[i] - lowest);
            lowest = min(lowest, prices[i]);
            maxWithEnd.push_back(maxProfit);
        }
        maxProfit = 0;
        int highest = prices.back();
        int ret = maxWithEnd.back();
        for (int i = size - 2; i > -1; i--) {
            maxProfit = max(maxProfit, highest - prices[i]);
            highest = max(highest, prices[i]);
            ret = max(ret, maxProfit + maxWithEnd[i]);
        }
        return ret;
    }
};


int main() {
    Solution *s = new Solution();
    vector<int> prices{1, 2, 3, 4, 5, 6};
    prices.front();

    return 0;
}
