//使用dfs。如果desriredTotal小于等于0，该用户一定赢。如果所有的数相加都比desriredTotal小，该用户则一定输。
//dfs，使用string表示当前状态，state[i]为'1'表示数字i+1已经选过了，为'0'则表示没有选过。进行深度优先遍历，
//对于每一个没选的数，尝试进行选择，看最终能否赢得比赛，并且使用hash_map存放中间结果，避免重复处理子问题。
//注意要对表示状态的字符串设置正确的值。上一个值遍历完成之后要设置回来。采用复制的方式创建字符串key,而不是直接将state作为
//hash_map的key
class Solution{
public:
    bool canIWin(int maxChoosableInteger, int desriredTotal){
        if(desriredTotal <= 0)
            return true;
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desriredTotal)
            return false;
        string state(maxChoosableInteger,'0');
        unordered_map<string,bool> map;
        return help(desriredTotal,state,map);
    }
private:
    bool help(int total,string &state,unordered_map<string,bool> &map){
        string key(state);
        if(map.count(key)){
            return map[key];
        }
        for(int i=0;i<state.size();++i){
            if(state[i] == '0'){
                state[i] = '1';
                if(total<=i+1 or !help((total-i-1),state,map)){
                    map[key] = true;
                    state[i] = '0';
                    return true;
                }
                state[i] = '0';
            }
        }
        map[key] = false;
        return false;
    }
};
