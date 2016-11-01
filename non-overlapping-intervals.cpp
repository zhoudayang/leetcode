/*
	这道题给了我们一堆区间，让我们求需要至少移除多少个区间才能使剩下的区间没有重叠，那么我们首先要给区间排序，根据每个区间的start来做升序排序，
	然后我们开始要查找重叠区间，判断方法是看如果前一个区间的end大于后一个区间的start，那么一定是重复区间，此时我们结果res自增1，我们需要删除一个，
	那么此时我们究竟该删哪一个呢，为了保证我们总体去掉的区间数最小，我们去掉那个end值较大的区间，而在代码中，我们并没有真正的删掉某一个区间，
	而是用一个变量last指向上一个需要比较的区间，我们将last指向end值较小的那个区间；如果两个区间没有重叠，那么此时last指向当前区间，继续进行下一次遍历
*/

class Solution {
 public:
  int eraseOverlapIntervals(vector<Interval> &intervals) {
    if(intervals.size()<2)
      return 0;
    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
      return a.start < b.start;
    });
    int result = 0;
    int last = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start < intervals[last].end){
        ++ result;
        if(intervals[last].end > intervals[i].end)
          last = i;
      }
      else
        last = i;
    }
    return result;
  }
};