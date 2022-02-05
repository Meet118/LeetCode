class Solution {
public:
    vector<vector<int>> g;
    int n, m;
    vector<int> fx = {1, -1, 0, 0}, fy = {0, 0, 1, -1};
    int ans = 0;

    void dfs(int i, int j, int s) {
        s += g[i][j];
        ans = max(ans, s);
        int t = g[i][j];
        g[i][j] = 0;
        for (int k = 0; k < 4; k ++ ) {
            int x = i + fx[k], y = j + fy[k];
            if (x < 0 || x >= n | y < 0 || y >= m || g[x][y] == 0)
                continue;
            dfs(x, y, s);
        }
        g[i][j] = t;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (g[i][j] != 0)
                    dfs(i, j, 0);
            }
        return ans;
    }
};
