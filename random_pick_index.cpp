/*
思路：采用Reservoir sampling 算法。该算法的实质是在序列流中取一个数，如何确保随机性，即取出某个数据的概率为:1/(已读取数据个数)
　　假设已经读取n个数，现在保留的数是Ax，取到Ax的概率为(1/n)。

　　对于第n+1个数An+1，以1/(n+1)的概率取An+1，否则仍然取Ax。依次类推，可以保证取到数据的随机性。

数学归纳法证明如下：

　　　　当n=1时，显然，取A1。取A1的概率为1/1。

           假设当n=k时，取到的数据Ax。取Ax的概率为1/k。

           当n=k+1时，以1/(k+1)的概率取An+1，否则仍然取Ax。

　　　　(1)如果取Ak+1，则概率为1/(k+1)；

　　　　(2)如果仍然取Ax，则概率为(1/k)*(k/(k+1))=1/(k+1)

　　所以，对于之后的第n+1个数An+1，以1/(n+1)的概率取An+1，否则仍然取Ax。依次类推，可以保证取到数据的随机性。

搞清楚这个道理之后，我们记录第一个值为target的下标，同时记录出现target数的次数，对于第n个出现的target，我们设最后取其作为返回的下标的概率满足p=1/n,这样就能保证取到值为target的序列中任意一个数的概率相等。
 */
class Solution {
public:
    Solution(vector<int> nums) :
            nums_(std::move(nums)) {

    }
    int pick(int target) {
        int count = 0;
        int res = -1;
        int size = nums_.size();
        for (int i = 0; i < size; ++i) {
            if (nums_[i] == target) {
                if (++count == 1)
                    res = i;
                else if (rand() % count == 0)
                    res = i;
            }
        }
        return res;
    }

private:
    vector<int> nums_;
};