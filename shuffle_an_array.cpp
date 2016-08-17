// 思路：遍历数组，将数组中第i个数和其后面的某个随机位置的数交换位置。
class Solution {
private:
    vector<int> nums;
    int size;
public:
    Solution(vector<int> nums) {
        this->nums= nums;
        this->size = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> results(nums);
        for(int i=0;i<size;i++){
            int pos = rand()%(size-i);
            swap(results[i],results[i+pos]);
        }
        return results;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */