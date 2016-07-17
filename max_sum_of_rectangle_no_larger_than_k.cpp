/*
	解题思路详见博客：http://www.cnblogs.com/zhoudayang/p/5679496.html
*/
#include<iostream>
#include<vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        int ret = INT_MIN;
        for (int l = 0; l < col; l++) {
            vector<int> sums(row, 0);
            for (int r = l; r < col; r++) {
                for (int i = 0; i < row; i++)
                    sums[i] += matrix[i][r];
                // Find the max subarray no more than K
                set<int> sumSet;
                sumSet.insert(0);
                int curSum = 0;
                int curMax = INT_MIN;
                for (auto sum:sums) {
                    curSum += sum;
                    auto it = sumSet.lower_bound(curSum - k);
                    if (it != sumSet.end())
                        curMax = max(curMax, curSum - *it);
                    sumSet.insert(curSum);
                }
                ret = max(ret, curMax);
            }
        }
        return ret;
    }
};

int main() {


   
}