class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> st(n, vector<int>(m));
        for (int i = 0; i < n; i ++ ) {
            if (grid[i][0] == 1)
                q.push({i, 0}), st[i][0] = 1;
            if (grid[i][m - 1] == 1)
                q.push({i, m - 1}), st[i][m - 1] = 1;
        }
        for (int i = 1; i < m - 1; i ++ ) {
            if (grid[0][i] == 1)
                q.push({0, i}), st[0][i] = 1;
            if (grid[n - 1][i] == 1)
                q.push({n - 1, i}), st[n - 1][i] = 1;
        }
        vector<int> fx = {1, -1, 0, 0}, fy = {0, 0, 1, -1};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int x = t.first + fx[i], y = t.second + fy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || st[x][y] == 1 || grid[x][y] == 0)
                    continue;
                st[x][y] = 1;
                q.push({x, y});
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (grid[i][j] == 1 && st[i][j] == 0)
                    ans ++ ;
        return ans;
    }
};
