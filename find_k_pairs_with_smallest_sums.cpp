//思路：将所有的组合加入优先队列，较小的pair在前，然后依次出列，直至出列数量达到k或者最大组合数目
struct Pair{
    Pair(int sum,pair<int,int> p){
        this->sum =sum;
        this->p=p;
    }
    int sum;
    pair<int,int> p;
    bool operator < (const Pair &a) const{
        return a.sum<sum;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<pair<int,int>> ret;
        if(!size1||!size2)
            return ret;
        priority_queue <Pair> q;
        for(int i=0;i<size1;i++){
            for(int j=0;j<size2;j++){
                int sum = nums1[i]+nums2[j];
                auto p = make_pair(nums1[i],nums2[j]);
                q.push(Pair(sum,p));
            }
        }
        for(int i=0;i<k&&i<size1*size2;i++){
            auto one = q.top();
            q.pop();
            ret.push_back(one.p);
        }
        return ret;
    }
};
