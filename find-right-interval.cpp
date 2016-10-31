class Solution {
 public:
  vector<int> findRightInterval(vector <Interval> &intervals) {
    vector<int> results(intervals.size(), -1);
    map<int,int> container;
    for(int i =0;i<intervals.size();++i){
      container[intervals[i].start] = i;
    };
    for(int i =0;i<intervals.size();++i){

      int end = intervals[i].end;
      auto it = container.find(end);
      if(it != container.end()){
        results[i] = it->second;
      }
    }
    return results;
  }
};