class Solution {
public:
    vector<string> g;

    int get(char c) {
        int res = 0;
        for (int i = 0; i < 3; i ++ )
            for (int j = 0; j < 3; j ++ )
                if (g[i][j] == c)
                    res ++ ;
        return res;
    }

    bool check(char c) {
        for (int i = 0; i < 3; i ++ ) {
            if (g[i][0] == c && g[i][1] == c && g[i][2] == c) return true;
            if (g[0][i] == c && g[1][i] == c && g[2][i] == c) return true;
        }
        if (g[0][0] == c && g[1][1] == c && g[2][2] == c) return true;
        if (g[0][2] == c && g[1][1] == c && g[2][0] == c) return true;
        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        g = board;
        int cx = get('X'), co = get('O');
        bool fx = check('X'), fo = check('O');
        if (cx != co && cx != co + 1) return false;
        if (fx && fo) return false;
        if (fx && cx != co + 1) return false;
        if (fo && cx != co) return false;
        return true;
    }
};
