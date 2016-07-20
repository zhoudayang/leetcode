/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*

 */
 bool operator <(const Interval &a,const Interval & b){
     return a.start<b.start;
 }
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        //在set中找到Interval中start大于等于val的第一个值
        auto it =nums.lower_bound(Interval(val,val));
        //如果set中前一个元素和val重合，那么将it前移一位，
        if(it!=nums.begin() and (--it)->end+1<val){
            it++;
        }
        //上述操作使得it指向第一个和val有交集的Interval
        int start=val,end=val;
        // 如果it指向的Interval和val有交集，那么根据val和it的值进行合并，并删除it对应的Interval
        while(it!=nums.end() and it->start-1<=val and it->end+1>=val){
            start =min(start,it->start);
            end = max(end,it->end);
            it =nums.erase(it);
        }
        //  插入合并范围的之后的Interval
        nums.insert(it,Interval(start,end));
    }
    // 将set转换为vector，并返回
    vector<Interval> getIntervals() {
        return vector<Interval> (nums.begin(),nums.end());
    }
private:
    set<Interval> nums;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */