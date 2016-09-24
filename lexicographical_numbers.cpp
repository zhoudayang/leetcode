/*
    The idea is pretty simple. If we look at the order we can find out we just keep adding digit from 0 to 9 to every digit and make it a tree.
    Then we visit every node in pre-order. 
           1        2        3    ...
          /\        /\       /\
       10 ...19  20...29  30...39   ....

 */

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> results;
        //lexical order number begin with 1
        for(int i=1;i<10;++i){
            helper(i,n,results);
        }
        return results;
    }

    void helper(int cur,int n,vector<int> &ret){
        if(cur>n){
            return;
        }else{
            ret.push_back(cur);
            for(int i=0;i<10;++i){
                if(cur*10+i>n)
                    return;
                helper(cur*10+i,n,ret);
            }
        }
    }
};