class Solution{
public:
    string shortestPalindrome(string s){
        string reverse_str = string(s.rbegin(),s.rend());
        string connection_str = s + "#" + reverse_str;
        vector<int> common_len(connection_str.size(),0);
        int k = 0;
        for(int i=1;i<connection_str.size();i++){
            while(connection[i]!=connection[k] and k > 0 ){
                k = common_len[k-1];
            }
            if(connection[k] == connection[i]){
                common_len[i] = ++k;
            }
            else
                common_len[i] = 0;
        }
        int common_length = common_len.back();
        return reverse_str.substr(0,s.size()-common_length) + s;
    }
}
