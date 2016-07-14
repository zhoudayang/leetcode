// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        //init left and right
        int l=1,r=n;
        //while l<=r
        while(l<=r){
            //mid =l+((r-l)>>1) 而不是 mid=(r+l)/2, 会造成溢出
            int mid = l +((r-l)>>1);
            int ret =guess(mid);
            //found it! return mid
            if(ret==0)
                return mid;
            //the number is bigger,in the right part
            else if(ret==1)
                l=mid+1;
            //the number is smaller,int the left part
            else 
                r=mid-1;
        }
        //can't find it! 
        return -1;
    }
};
