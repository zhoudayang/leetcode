class Solution {
private:
    string helper(string s,int &i){
        string res;
        int size = s.size();
        while(i<size and s[i]!=']'){
            if(!isdigit(s[i])){
                res += s[i++];
            }
            else{
                int n = 0;
                while(isdigit(s[i]) and i < size){
                    n = n*10 + s[i]-'0';
                    i++;
                }
                i++;// for [ 
                string tmp = helper(s,i); // dfs to get string at next level 
                i++;// for ] 
                while(--n){
                    res += tmp;
                }
            }
        }
        return res;
    }
public:
    string decodeString(string s) {
        int i=0;
        return helper(s,i);
    }
};