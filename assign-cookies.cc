//简单的贪心题目：尽可能的满足要求低的孩子，直至手上的糖果不能满足任何孩子。
class Solution{
public:
    int findContentChildren(vector<int> & g,vector<int> &s){
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int result = 0;
        int idx = 0;
        for(int i=0;i<s.size()&&idx<g.size();++i){
            if(s[i]>=g[idx]){
                ++result;
                ++idx;
            }
        }
        return result;
    }
};
