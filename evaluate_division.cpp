//首先使用unordered_map<string, unordered_map<string, double>>类型的容器存储所有已知的除法结果，如果a/b！＝０，也将　b/a对应的结果存入容器中。
//接下来对于每一个查询结果，递归调用helper函数查找除法结果。在helper函数中使用unordered_set避免对同一值反复进行查找。如果在container容器中
// 能够直接找到结果，直接返回, 否则对于以begin开头的所有对应的边，查找使用边的另一顶点值开始是否能够在container中找到对应的值，即递归调用helper函数。
//如果找到了，注意要将后续helper函数返回的值乘以当前边对应的除法值。
// 参考:https://discuss.leetcode.com/topic/58312/c-0ms-hash-dfs-solution
class Solution {
public:
    vector<double>
    calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
    {
        unordered_map<string, unordered_map<string, double>> container;
        vector<double> results;
        int size = equations.size();
        for (int i = 0; i<size; ++i)
        {
            const auto& pair = equations[i];
            const double value = values[i];
            container[pair.first].insert(make_pair(pair.second, value));
            if (value!=0)
            {
                container[pair.second].insert(make_pair(pair.first, 1.0/value));
            }
        }
        for (auto query:queries)
        {
            unordered_set<string> filter;
            double res;
            if ((res = helper(query.first, query.second, container, filter))!=0)
            {
                results.push_back(res);
            }
            else
                results.push_back(-1);
        }
        return results;
    }

    double
    helper(const string& begin, const string& end, unordered_map<string, unordered_map<string, double>>& container,
            unordered_set<string>& filter)
    {
        if (container[begin].count(end))
        {
            return container[begin][end];
        }
        for (auto pair:container[begin])
        {
            if (!filter.count(pair.first))
            {
                filter.insert(pair.first);
                double tmp = helper(pair.first, end, container, filter);
                if (tmp!=0)
                    return pair.second*tmp;
            }
        }
        return 0;
    }

};
