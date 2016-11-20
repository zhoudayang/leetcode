//使用hashset存放所有岛屿对应的坐标，对于每个岛屿的4条边，如果其不和其他岛屿的边相邻或者这条边在边界上
//就将这条边记为整个岛屿边长的一部分。
namespace std{
    //self definied hash function
    struct hashFunc{
        std::size_t operator()(const pair<int,int> & key) const{
            using std::hash;
            return (hash<int>()(key.first)^(hash<int>()(key.second)));
        }
    }
}

class Solution{
public:
    int islandPerimeter(vector<vector<int>> &grid){
        typedef pair<int,int> pos;
        unordered_set<pos,hashFunc> positions;
        int dp[2][4] = {{1,-1,0,0},{0,0,1,-1}};
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 1)
                    positions.insert(make_pair(i,j));
             }
        }
        auto valid = [m,n](pos p) -> bool {
            int x = p.first;
            int y = p.second;
            return (x>=0 and x<m) and (y>=0 and y<n);
        }
        for(auto pair:positions){
            int x = p.first;
            int y = p.second;
            for(int i=0;i<4;++i){
                pos neighbor = make_pair(x+dp[0][i],y+dp[1][i]);
                if(!valid(neighbor)){
                    ++result;
                }
                else if (!positions.count(neighbor))
                    ++result;
            }
        }
        return result;
    }
};
