class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size(), m = grid[0].size();
        int w = grid[row][col];
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<int> fx = {0, 0, 1, -1}, fy = {1, -1, 0, 0};
        vector<vector<int>> st(n, vector<int>(m)); //0表示未搜过 1表示搜过 2表示搜过且是边界
        st[row][col] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            bool f = false;
            for (int i = 0; i < 4; i ++ ) {
                int a = x + fx[i], b = y + fy[i];
                if (a < 0 || a >= n || b < 0 || b >= m || grid[a][b] != w)
                    f = true;
                else if (grid[a][b] == w && st[a][b] == 0) {
                    st[a][b] = 1;
                    q.push({a, b});
                }
            }
            if (f)
                st[x][y] = 2;
        }
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (st[i][j] == 2)
                    grid[i][j] = color;
        return grid;
    }
};
