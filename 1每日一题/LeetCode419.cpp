//只统计左上角
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for (int i = 0; i < board.size(); i ++ )
            for (int j = 0; j < board[0].size(); j ++ ) {
                if (i && board[i - 1][j] == 'X') continue;
                if (j && board[i][j - 1] == 'X') continue;
                if (board[i][j] == 'X')
                    ans ++ ;
            }
        return ans;
    }
};
