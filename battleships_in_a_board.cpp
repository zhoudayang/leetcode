/*
	Suppose ship's head is on left or top side.
	Traverse left to right, top to down.
	Increment total number if we find the head.
 */
class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(board[i][j] == 'X' && !((i>0 && board[i-1][j]=='X')||(j>0 && board[i][j-1]=='X')))
                    ++ result;
            }
        }
        return result;
    }
};