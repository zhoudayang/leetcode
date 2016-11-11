class Solution{
 public:
  void wiggleSort(vector<int> &nums){
    vector<int> temp(nums);
    sort(temp.begin(),temp.end());
    for(int i = nums.size()-1,j=0,k=i/2+1;i>=0;--i){
      //odd
      if(i&1){
        nums[i] = temp[k++];
      }
      else{
        nums[i] = temp[j++];
      }
    }
  }
};

/*
Sort and then write the smaller half of the numbers on the even indexes and the larger half of the numbers on the odd indexes, both from the back. Example:

Small half:    4 . 3 . 2 . 1 . 0 .
Large half:    . 9 . 8 . 7 . 6 . 5
----------------------------------
Together:      4 9 3 8 2 7 1 6 0 5
So write nums from the back, interweaving sorted[0..4] (indexed by j) and sorted[5..9] (indexed by k).
*/
