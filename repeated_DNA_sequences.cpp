//思路：对每一个长度为10的子串，利用set判断其是否重复出现，并进行去除，找到重复出现的那些子串
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> seen;
        set<string> repeated;
        int length = s.size();
        for(int i=0;i+9<length;i++){
            string ten = s.substr(i,10);
            if(!seen.insert(ten).second)
                repeated.insert(ten);
        }
        vector<string>ret;
        copy(repeated.begin(),repeated.end(),back_inserter(ret));
        return ret;
    }
};
