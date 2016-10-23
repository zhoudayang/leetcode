class Solution {
public:
    int findNthDigit(int n)
    {
        long count = 9;
        int start = 1;
        int len = 1;
        //find the length of the number where nth digit is from 
        while (n>len*count)
        {
            n -= len*count;
            ++len;
            count *= 10;
            start *= 10;
        }
        //get the actual number where nth digit is from
        start += (n-1)/len;
        string s = to_string(start);
        //find the nth digit and return
        return s[(n-1)%len]-'0';

    }
};