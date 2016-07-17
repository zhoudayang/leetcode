/*
	解题思路详见博客：http://www.cnblogs.com/zhoudayang/p/5679496.html
   思路：

　　	使用l和r划定长方形的左右边界范围，然后在这个范围内，依次记录长方形的上界固定为第一行，
　　	下界从第一行到最后一行对应的长方形的和到数组sum。现在问题转换为寻找最合适的sum[j]-sum[i](j和i对应长方形的上下界)，
　　	使得该值不大于k，但是最接近k。这个问题可以从Quora上找到解答：
　　	
　　You can do this in O(nlog(n))

　　First thing to note is that sum of subarray (i,j] is just the sum of the first j elements less the sum of the first i elements. Store these cumulative sums in the array cum. Then the problem reduces to finding  i,j such that i<j and cum[j]−cum[i] is as close to k but lower than it.

　　To solve this, scan from left to right. Put the cum[i] values that you have encountered till now into a set. When you are processing cum[j] what you need to retrieve from the set is the smallest number in the set such which is not smaller than cum[j]−k. This lookup can be done in O(log(n)) using lower_bound. Hence the overall complexity is O(nlog⁡(n)).

　　Here is a c++ function that does the job, assuming that K>0 and that the empty interval with sum zero is a valid answer. The code can be tweaked easily to take care of more general cases and to return the interval itself.

	int best_cumulative_sum(int ar[],int N,int K)
	{
	    set<int> cumset;
	    cumset.insert(0);
	    int best=0,cum=0;
	    for(int i=0;i<N;i++)
	    {
	        cum+=ar[i];
	        set<int>::iterator sit=cumset.lower_bound(cum-K);
	        if(sit!=cumset.end())best=max(best,cum-*sit);
	        cumset.insert(cum);
	    }
	    return best;
	}
   在上述基础之上，稍加修改，就能够完成此题了，代码如下：
　　
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
