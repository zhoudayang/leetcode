//思路：贪心算法，每次取到局部最小或者最大再进行反转
/*
参见discuss：
At first, I misunderstood the question and tried to find the maximum length of a consecutive wiggle subsequence. However, the subsequence does not need to be consecutive, then this question can be pretty simple. You just need to count the maximum length and do not need to compare.

As an element itself can form a wiggle subsequence, the initial value of the count should be 1 (you should return 0 if you are given an empty input). Flag is used to indicate what kind of element you should find next to form the wiggle subsequence.

In this algorithm, the first step is that you should find the first pair of elements which are not equal. So I set a flag = 0 as the initial value to indicate I am actually finding that first pair. Then flag = 1 means you need to move on and find the element nums[i] that nums[i] < nums[i-1] to form a longer wiggle subsequence, flag = -1 means you need to find the element nums[i] that nums[i] > nums[i-1] and so on. Every time you successfully find such an element, you should increase the count by 1. Finally, simply return the counted length.

Update (hints on the greedy algorithm):
For example, the input is: [1,12,10,8,7,9,11,13,12,5].
After picking 1 and 12, you form a wiggle subsequence [1,12]. Then you can pick 10, 8, 7, why do you need to pick 7 but not 10 or 8? Again, you obtain a wiggle subsequence [1,12,7] after picking 7, the next element you should pick is 13, why? If some parts of the input sequence is monotonically increasing/decreasing, how to choose the element you want (local maximum/minimum)?


 */
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        int count = 1;
        int flag = 0;
        for (int i = 1; i < size; i++) {
            if (nums[i] < nums[i - 1] && (flag == 1 || flag == 0)) {
                flag = -1;
                count++;
            }
            if (nums[i] > nums[i - 1] && (flag == -1 || flag == 0)) {
                flag = 1;
                count++;
            }
        }
        return count;
    }
};