class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> a(n, vector<int>(m, -1));
        vector<vector<int>> b(n, vector<int>(m, -1));
        vector<vector<int>> f {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i ++ )
            q.push({i, 0}), a[i][0] = 1;
        for (int i = 1; i < m; i ++ )
            q.push({0, i}), a[0][i] = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int x = t.first + f[i][0], y = t.second + f[i][1];
                if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] != -1) continue;
                if (heights[x][y] >= heights[t.first][t.second]) {
                    q.push({x, y});
                    a[x][y] = 1;
                }
            }
        }
        for (int i = 0; i < n; i ++ )
            q.push({i, m - 1}), b[i][m - 1] = 1;
        for (int i = 0; i < m - 1; i ++ )
            q.push({n - 1, i}), b[n - 1][i] = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int x = t.first + f[i][0], y = t.second + f[i][1];
                if (x < 0 || x >= n || y < 0 || y >= m || b[x][y] != -1) continue;
                if (heights[x][y] >= heights[t.first][t.second]) {
                    q.push({x, y});
                    b[x][y] = 1;
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (a[i][j] == b[i][j] && a[i][j] == 1)
                    ans.push_back({i, j});
            }
        return ans;
    }
};
