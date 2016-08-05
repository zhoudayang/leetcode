/*
思路：们首先把图建立起来，通过邻接链表来建立。由于题目要求解法按字母顺序小的，那么我们考虑用multiset，可以自动排序。
等我们图建立好了以后，从节点JFK开始遍历，只要当前节点映射的multiset里有节点，我们取出这个节点，将其在multiset里删掉，然后继续递归遍历这个节点，由于题目中限定了一定会有解，那么等图中所有的multiset中都没有节点的时候，我们把当前节点存入结果中，然后再一层层回溯回去，将当前节点都存入结果，那么最后我们结果中存的顺序和我们需要的相反的，我们最后再翻转一下即可.
 */
//todo at another solution 
class Solution {
public:
    vector <string> findItinerary(vector <pair<string, string>> tickets) {
        unordered_map <string, multiset<string>> trips;
        vector <string> paths;
        for (auto ticket:tickets) {
            trips[ticket.first].insert(ticket.second);
        }
        //begin with JFK
        helper(trips, paths, "JFK");
        //reverse paths
        reverse(paths.begin(), paths.end());
        return paths;
    }

    void helper(unordered_map <string, multiset<string>> &trips, vector <string> &paths, string start) {
        while (trips[start].size()) {
            auto it = trips[start].begin();
            string next = *it;
            trips[start].erase(it);
            helper(trips, paths, next);
        }
        paths.push_back(start);
    }
};