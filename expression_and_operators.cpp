// main idea dfs 
// which need to concern is the plus case 

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        // call dfs function
        helper(results,num,"",0,0,target);
        return results;
    }
    // results constains the result, num for remain number string, t for temp string which store middle result,
    // last is the value of last add number ,cur is the current value ,target -> target
    void helper(vector<string>& results,string num,string t,long long last,long long cur,int  target){
        if(num.empty()){
            if(cur==target)
                results.push_back(t);
            return;
        }
        // i for substr num into two part 
        for(int i = 1;i<=num.size();i++){
            string number = num.substr(0,i);
            //filter for illegal number, no leading zeros
            if(number.size()>1 and number[0]=='0')
                return;
            string nextNum = num.substr(i);
            long long value = stoll(number);
            if(!t.empty()){
                // for + case 
                helper(results,nextNum,t+"+"+number,value,cur+value,target);
                //for - case 
                helper(results,nextNum,t+"-"+number,-value,cur-value,target);
                //for * case , please concern the plus case , it is different
                helper(results,nextNum,t+"*"+number,last*value,cur-last+last*value,target);
            }
            else // for t empty case
                helper(results,nextNum,number,stoll(number),stoll(number),target);
        }
    }
};