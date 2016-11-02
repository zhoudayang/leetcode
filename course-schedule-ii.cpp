//simple topsort with bfs 
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> degress(numCourses, 0);
        for (auto &pair:prerequisites)
        {
            int from = pair.second;
            int to = pair.first;
            edges[from].push_back(to);
            ++degress[to];
        }
        vector<int> result;
        queue<int> zeros;
        for (int i = 0; i < numCourses; ++i)
            if (degress[i] == 0)
                zeros.push(i);
        for (int i = 0; i < numCourses; ++i)
        {
            if (zeros.empty())
                return {};
            int zero = zeros.front();
            zeros.pop();
            result.push_back(zero);
            for (int to:edges[zero])
            {
                if (--degress[to] == 0)
                    zeros.push(to);
            }
        }
        return result;
    }
};
