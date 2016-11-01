/*
	������������һ�����䣬����������Ҫ�����Ƴ����ٸ��������ʹʣ�µ�����û���ص�����ô��������Ҫ���������򣬸���ÿ�������start������������
	Ȼ�����ǿ�ʼҪ�����ص����䣬�жϷ����ǿ����ǰһ�������end���ں�һ�������start����ôһ�����ظ����䣬��ʱ���ǽ��res����1��������Ҫɾ��һ����
	��ô��ʱ���Ǿ�����ɾ��һ���أ�Ϊ�˱�֤��������ȥ������������С������ȥ���Ǹ�endֵ�ϴ�����䣬���ڴ����У����ǲ�û��������ɾ��ĳһ�����䣬
	������һ������lastָ����һ����Ҫ�Ƚϵ����䣬���ǽ�lastָ��endֵ��С���Ǹ����䣻�����������û���ص�����ô��ʱlastָ��ǰ���䣬����������һ�α���
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