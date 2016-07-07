/*
    思路：使用set维护一个大小为k的窗口，数字插入set，set会自动将其排序。依次遍历数组中的每一个数。
    尝试在数组中找大于或者等于且最接近nums[i]-t的数。如果找不到，说明set中的每一个数和nums[i]的差值都大于t，
    不满足条件，继续。否则，进一步检查找到的数和nums[i]的差值是否小于等于t，满足条件说明有这样的k和t存在，返回true。
    如果一直都没有返回，最后返回false，表示找到不到这样的k和t。
    此处找到的数是最可能满足和nums[i]的差值小于或等于t的数，其他数都比这个数大，意味着和nums[i]-t的距离更大,更不可能满足和nums[i]的差值小于或等于t。
    至于为什么这里使用multiset，是因为，如果存在两个相同的数，且他们之间的窗口小于k，则他们之间的差为0，一定小于或等于t。
 */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        //使用set维护一个大小不大于k的窗口
        set<int> container;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (i > k)
                //保证set的大小不大于k
                container.erase(nums[i - k - 1]);
            //找大于或者等于nums[i]-t且最接近nums[i]-t的元素
            //如果set中所有元素的值都比nums[i]-t小,返回空
            auto it = container.lower_bound(nums[i] - t);
            //如果it==container.end() 表明set中最大的数都比nums[i]-t小
            //此时set中的每一个数和nums[i]的差都大于t,不满足条件
            if (it != container.end() and abs(nums[i] - *it) <= t)
                //在it!=container.end()的条件下,再检查这两个数的差的绝对值是否小于等于t
                return true;
            //向set中插入nums[i]
            container.insert(nums[i]);
        }
        return false;
    }
};