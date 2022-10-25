class Solution {
public:
    vector<vector<int>> g;
    int n;
    vector<vector<int>> f {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}
    };
    queue<pair<int, int>> q;
    vector<vector<int>> d;

    int shortestBridge(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        d.resize(n, vector<int>(n, 1e8));
        bool flag = true;
        for (int i = 0; i < n && flag; i ++ )
            for (int j = 0; j < n && flag; j ++ ) {
                if (g[i][j] == 1) {
                    dfs(i, j);
                    flag = false;
                }
            }
        
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int a = t.first + f[i][0], b = t.second + f[i][1];
                if (a >= 0 && a < n && b >= 0 && b < n && d[a][b] > d[t.first][t.second] + 1) {
                    d[a][b] = d[t.first][t.second] + 1;
                    if (g[a][b]) return d[a][b] - 1;
                    q.push({a, b});
                }
            }
        }
        
        return 0;
    }

    void dfs(int x, int y) {
        g[x][y] = 2;
        d[x][y] = 0;
        q.push({x, y});
        for (int i = 0; i < 4; i ++ ) {
            int a = x + f[i][0], b = y + f[i][1];
            if (a >= 0 && a < n && b >= 0 && b < n && g[a][b] == 1)
                dfs(a, b);
        }
    }
};
