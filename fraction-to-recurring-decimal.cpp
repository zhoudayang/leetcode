class Solution{
public:
	string fractionToDecimal(int64_t n,int64_t d){
		if(n == 0)
			return "0";
		string result;
		//判断除法的符号
		//这里使用了异或运算
		if((n>0)^(d>0))
			result += "-";
		n = abs(n);
		d = abs(d);
		//得到除法的整数结果部分
		result += to_string(n/d);
		//如果能够整除，直接返回
		if(n%d==0)
			return result;
		result += ".";
		unordered_map<int,int> map;
		for(int64_t r = n%d;r>0;r%=d){
			//如果被除数重复出现了，找到了一个完整的循环，插入括号
			if(map.count(r))
			{
				result.insert(map[r],1,'(');
				result += ")";
				break;
			}
			//记录这一个被除数的位置
			map[r] = result.size();
			//模拟除法，后撤一位，这时被除数要乘以10
			r *= 10;
			result += to_string(r/d);
		}
		return result;
	}
};