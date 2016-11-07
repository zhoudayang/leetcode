//思路：贪心，首先依据代码中的规则对point进行排序(首先按照坐标开始值，再按照坐标结束值从小到大进行排序),然后
//利用贪心算法，尽可能多地使得一个arrow能够穿过更多的气球，注意更新arrow_limit。
//请注意自定义cmp函数的写法！
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty())
            return 0;
        sort(points.begin(),points.end(),[](const pair<int,int >&a,const pair<int,int> &b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        int result = 1;
        int arrow_limit = points[0].second;
        for(int i = 1;i<points.size();++i){
            if(points[i].first <= arrow_limit){
                arrow_limit = min(points[i].second,arrow_limit);
            }
            else{
                arrow_limit = points[i].second;
                ++result;
            }
        }
        return result;
    }
};