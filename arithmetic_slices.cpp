class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        int size = A.size();
        vector<int> dp(size,0);
        for(int i=2;i<size;i++){
 	    // if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
            // equals to:
            //      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // it is how dp[i] = dp[i-1] + 1 comes
            if(A[i]-A[i-1] == A[i-1]-A[i-2]){
                dp[i] = dp[i-1] + 1;
            }
            result += dp[i];
        }
        return result;
    }
};
