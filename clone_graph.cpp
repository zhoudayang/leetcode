#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x):label(x){}

};
//思路 dfs
class Solution {
private:
    unordered_map<int,UndirectedGraphNode *> map;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //如果node为空,那么返回NULL
        if(!node)
            return NULL;
        //如果node节点已经创建完毕,直接返回这个节点
        if(map.count(node->label)){
            return map[node->label];
        }
        //赋值cloned节点
        UndirectedGraphNode *cloned = new UndirectedGraphNode(node->label);
        //记录该节点,避免重复创建
        map[node->label] =cloned;
        //加入neighbor节点,每个neighbor节点都递归调用cloneGraph进行复制
        for(auto neighbor:node->neighbors)
            cloned->neighbors.push_back(cloneGraph(neighbor));
        //返回复制完成后的节点
        return cloned;
    }
};
int main() {


    return 0;
}