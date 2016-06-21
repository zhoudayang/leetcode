#include<iostream>
#include<unordered_set>
#include<queue>
#include<set>

using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1= s1.size();
        int len2= s2.size();
        int len = s3.size();
        if(len1+len2!=len)
            return false;
        //用于判断是否已经将点加入队列
        unordered_set<int> visited;
        queue<pair<int,int>>q;
        //起始位置
        q.push(make_pair(-1,-1));
        //加上起始位置对应的那一列
        int cols= len2+1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first+1;
            int col = it.second+1;
            //到达右下角
            if(row+col==len)
                return true;
            if(row+col<len){
                //需要到达的下一点
                char next = s3[row+col];
                if(row<len1 &&s1[row]==next)//加上１防止０的影响
                    //insert返回值　std::pair<iterator, bool>　分别对应迭代器以及ｓｅｔ中是否有这个元素
                    if(visited.insert((row+1)*cols+col).second)
                        q.push(make_pair(row,col-1));
                if(col<len2&&s2[col]==next)//加上１防止０的影响
                    if(visited.insert(row*cols+col+1).second)
                        q.push(make_pair(row-1,col));
            }
        }
        return false;
    }
};
int main() {
    Solution *s = new Solution();
    cout<<s->isInterleave("aa","ab","aaba");

    return 0;
}
/*
If we expand the two strings s1 and s2 into a chessboard, 
then this problem can be transferred into a path seeking problem from the top-left corner to the bottom-right corner.
The key is, each cell (y, x) in the board corresponds to an interval between y-th character in s1 and x-th character in s2. 
And adjacent cells are connected with like a grid. A BFS can then be efficiently performed to find the path.

Better to illustrate with an example here:

Say s1 = "aab" and s2 = "abc". s3 = "aaabcb". Then the board looks like

o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
b     b     b     b
|     |     |     |
o--a--o--b--o--c--o
Each "o" is a cell in the board. We start from the top-left corner, and try to move right or down. 
If the next char in s3 matches the edge connecting the next cell, then we're able to move.
When we hit the bottom-right corner, this means s3 can be represented by interleaving s1 and s2. 
One possible path for this example is indicated with "x"es below:

x--a--x--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--x--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--x--b--x--c--x
|     |     |     |
b     b     b     b
|     |     |     |
o--a--o--b--o--c--x
Note if we concatenate the chars on the edges we went along, it's exactly s3. 
And we went through all the chars in s1 and s2, in order, exactly once.

url: https://leetcode.com/discuss/19973/8ms-c-solution-using-bfs-with-explanation

 */
