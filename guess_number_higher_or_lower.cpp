// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        // first test number n
        if(guess(n)==0)
            return n;
        //init left and right
        int l=1,r=n;
        while(l<r){
            //注意需要采取这种方式求mid，如果mid=(l+r)/2，容易越界
            int mid = l+((r-l)>>1);
            //test mid
            if(guess(mid)==0)
                return mid;
            //less than the number, in the right part
            else if(guess(mid)==1)
                l=mid;
            //bigger than the number, int the left part
            else if(guess(mid)==-1)
                r=mid;
        }
        //not found,return -1
        return -1;
    }
};
