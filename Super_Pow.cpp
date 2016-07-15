/*
    One knowledge: ab % k = (a%k)(b%k)%k
    Since the power here is an array, we'd better handle it digit by digit.
    One observation:
    a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * a^7 % k
    Looks complicated? Let me put it other way:
    Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
    f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(a, 123456)^10%k * f(a,7)%k=f(f(a, 123456),10) * f(a,7)%k;
    Implementation of this idea:
*/

class Solution {
public:
    int powmod(int a,int k){
        a=a%1337;
        int result=1;
        for(int i=0;i<k;i++)
            result = (result*a)%1337;
        return result;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty())
            return 1;
        int back = b.back();
        b.pop_back();
        return powmod(superPow(a,b),10)*powmod(a,back)%1337;
    }
};