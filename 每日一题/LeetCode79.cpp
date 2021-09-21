class Solution {
public:
    int n, m;
    vector<vector<char>> c;
    int fx[4] = {1, -1, 0, 0}, fy[4] = {0, 0, 1, -1};
    vector<vector<int>> st;

    bool dfs(int x, int y, string w, int idx) {
        if (w[idx] != c[x][y])
            return false;
        if (idx + 1 == w.size())
            return true;
        st[x][y] = 1;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + fx[i], b = y + fy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b])
                continue;
            if (dfs(a, b, w, idx + 1)) {
                return true;
            }
        }
        st[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        st.resize(n, vector<int>(m, 0));
        c = board;
        string w = word;
        bool f = true;
        for (int i = 0; i < n && f; i ++ )
            for (int j = 0; j < m && f; j ++ )
                    if (dfs(i, j, w, 0)) 
                        return true;
                
        return false;
    }
};