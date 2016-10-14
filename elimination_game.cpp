/*
	解题思路是每次遍历删除元素时，更新并用head记录数组第一个元素。每次遍历之后，数组相邻元素间隔step都会变成2倍，当数组个数为1时，head就是最后剩下的元素。
	那什么时候更新head呢？

	当我们从左边开始遍历删除元素时

	当我们从右边开始遍历元素，并且剩下的数组元素个数为奇数时

	例如：

	2,4,6,8,10

	从10开始移动，会删除10,6,2。数组的第一个元素head会被删除，因此需要更新head

	2,4,6,8,10,12

	从12从右至左遍历，我们会删除12,8,4，head此时依然是2
*/
class Solution {
public:
    int lastRemaining(int n)
    {
        bool left = true;
        int step = 1;
        int head = 1;
        int remain = n;
        while (remain>1)
        {
            if (left || remain%2==1)
                head += step;
            step *= 2;
            remain /= 2;
            left = !left;
        }
        return head;
    }

};