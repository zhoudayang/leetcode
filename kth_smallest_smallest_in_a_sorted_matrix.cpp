//思路：二分查找 查找每一行中大小小于mid对应的数字的个数，如果个数小于k，那么说明mid需要网上走，令l=mid+1，否则令r=mid，直到l和r收敛，此时l的值就是第k小的数字对应的值
//最简单的思路是将matrix合并成一个一维的数组，将数组排序之后直接返回第k个位置对应的数字，但是这种思路没有充分利用到原来matrix中每一行和每一列均排好序的性质。
class Solution{
    public:
	int kthSmallest(vector<vector<int>> &matrix,int k){
	    int n = matrix.size();
	    int l = matrix[0][0];
	    int r = matrix[n-1][n-1];
	    while(l<r){
		int mid = (r+l)>>1;
		int num =0;
		for(int i=0;i<n;i++){
		    num+= upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
		}
		if(num<k){
		    l =mid+1;
		}
		else
		    r=mid;
	    }
	    return l;
	}
}
