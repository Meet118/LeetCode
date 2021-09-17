class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        vector<int> st1(10);
        vector<int> st2(10);
        vector<int> st3(10);
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                //检查行和列
                if (board[i][j] != '.')
                    if ( ++ st1[board[i][j] - '0'] > 1)
                        return false;
                if (board[j][i] != '.')
                    if ( ++ st2[board[j][i] - '0'] > 1)
                        return false;
                //检查3*3
                int x = i / 3 * 3 + j / 3, y = i % 3 * 3 + j % 3;
                if (board[x][y] != '.')
                    if ( ++ st3[board[x][y] - '0'] > 1)
                        return false;
            }
            fill(st1.begin(), st1.end(), 0);
            fill(st2.begin(), st2.end(), 0);
            fill(st3.begin(), st3.end(), 0);
        }
        return true;
    }
};