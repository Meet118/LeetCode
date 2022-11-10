class Solution {
public:
    struct Node {
        int x, y, state, cnt;
    };

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<Node> q;
        int c = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (grid[i][j] == '@')
                    q.push({i, j, 0, 0});
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    c = max(c, grid[i][j] - 'a' + 1);
            }
        vector<vector<vector<int>>> st(n, vector<vector<int>>(m, vector<int>((1 << c))));
        vector<vector<int>> f {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t.state == (1 << c) - 1)
                return t.cnt;
            for (int i = 0; i < 4; i ++ ) {
                int a = t.x + f[i][0], b = t.y + f[i][1];
                if (a >= 0 && a < n && b >= 0 && b < m) {
                    char x = grid[a][b];
                    if (x == '#') continue;
                    int s = t.state;
                    if (x >= 'a' && x <= 'f') {
                        s = s | (1 << x - 'a');
                    }
                    if (st[a][b][s] == 1) continue;
                    if (x >= 'A' && x <= 'F' && !((t.state >> x - 'A') & 1)) continue;
                    q.push({a, b, s, t.cnt + 1});
                    st[a][b][s] = 1;
                }
            }
        }
        return -1;
    }
};
