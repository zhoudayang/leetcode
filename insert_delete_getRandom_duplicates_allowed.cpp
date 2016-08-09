//思路：使用unordered_map存储数val和其在vector<int> values中的下标。在remove操作中，将要删除的数的信息和最后一个数的位置互换，再进行删除。
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        it = nums.find(val);
        bool find = (it!=nums.end());
        if(!find){
            vector<int> pos = {values.size()};
            nums[val]=pos;
        }
        else 
            nums[val].push_back(values.size());
        values.push_back(val);
        return !find;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        it = nums.find(val);
        if(it==nums.end())
            return false;
        auto &pos = nums[val];
        int p = pos.back();
        pos.pop_back();
        int value = values.back();
        values.pop_back();
        if(value!=val){
            nums[value].back()=p;
            values[p]=value;
        }
        if(pos.empty())
            nums.erase(it);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand()%values.size();
        return values[pos];
    }
private:
    unordered_map<int,vector<int>>nums;
    vector<int> values;
    unordered_map<int,vector<int>>::iterator it;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */