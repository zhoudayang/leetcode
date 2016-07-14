// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n)==0)
            return n;
        int l=1,r=n;
        while(l<r){
            int mid = l+((r-l)>>1);
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==1)
                l=mid;
            else if(guess(mid)==-1)
                r=mid;
        }
        return l;
    }
};