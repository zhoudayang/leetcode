/*

首先利用map统计nums中所有元素的个数，记为count

变量min_num记录访问过元素的最小值

遍历数组nums，记当前数字为num

  将num在count中的计数-1，计数为0时将num从count中删去

  如果num < min_num，则更新min_num值为num

  否则，若count中大于min_num的最小元素< num，则返回true . 132 pattern为: min_num , 大于min_num的最小元素， num 

遍历结束，返回false
*/
class Solution{
public:
    bool find132pattern(vector<int> & nums){
        map<int,int> count;
        for(auto num:nums){
            count[num]++;
        }
        int min_num = INT_MAX;
        for(auto num:nums){
            if(--count[num]==0)
                count.erase(num);
            if(num<=min_num)
                min_num = num;
            else{
                auto it = count.upper_bound(min_num);
                if(it!=count.end() and it->first<num){
                    return true;
                }
            }
        }
        return false;
    }
}
