/*
	这道题给了我们一个字符串s和一个正整数k，让我们求一个最大子字符串并且每个字符必须至少出现k次。作为LeetCode第三次编程比赛的压轴题目，博主再一次没有做出来，虽然难度标识只是Medium。后来在网上膜拜学习了大神们的解法，发现我当时的没做出来的原因主要是卡在了如何快速的判断某一个字符串是否所有的元素都已经满足了至少出现k次这个条件，虽然我也用哈希表建立了字符和其出现次数之间的映射，但是如果每一次都要遍历哈希表中的所有字符看其出现次数是否大于k，未免有些不高效。而用mask就很好的解决了这个问题，由于字母只有26个，而整型mask有32位，足够用了，每一位代表一个字母，如果为1，表示该字母不够k次，如果为0就表示已经出现了k次，这种思路真是太聪明了，隐约记得这种用法在之前的题目中也用过，但是博主并不能举一反三(沮丧脸:()，还得继续努力啊。我们遍历字符串，对于每一个字符，我们都将其视为起点，然后遍历到末尾，我们增加哈希表中字母的出现次数，如果其小于k，我们将mask的对应位改为1，如果大于等于k，将mask对应位改为0。然后看mask是否为0，是的话就更新res结果，然后把当前满足要求的子字符串的起始位置j保存到max_idx中，等内层循环结束后，将外层循环变量i赋值为max_idx+1，继续循环直至结束，参见代码如下：
参考:http://www.cnblogs.com/grandyang/p/5852352.html
*/
class Solution {
public:
    int longestSubstring(string s, int k)
    {
        int result = 0;
        int i = 0;
        int size = s.size();
        while (i+k<size)
        {
            int max_index = i;
            vector<int> chs(26, 0);
            int mask =0;
            for (int j = i; j<size; ++j)
            {
                int val = s[j]-'a';
                ++chs[val];
                if(chs[val]>=k){
                    mask &= ~(1<<val);
                }
                else{
                    mask |= (1<<val);
                }
                if(mask==0){
                    result = max(result,j-i+1);
                    max_index = j;
                }
            }
            i=max_index+1;
        }
        return result;
    }
};
