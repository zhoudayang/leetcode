/*
    思路：首先统计每个字符出现的次数，然后依次遍历字符串，将从未出现的字符加入最终返回的字符串res中，
如果遍历到的字符比res末尾的字符字典位置靠前，且这个字符在之后还有出现，就将字符串末尾的字符弹出来，
保证最终返回的字符串字典序最小。
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> times (256,0);
        vector<bool> visited(256,false);
        for(auto ch:s)
            times[ch]++;
        string ret ="";
        for(auto ch:s){
            times[ch]--;
            if(visited[ch])
                continue;
            while(!ret.empty() and ch<ret.back() and times[ret.back()]){
                visited[ret.back()] = false;
                ret.pop_back();
            }
            visited[ch]= true;
            ret+=ch;
        }
        return ret;
    }
};