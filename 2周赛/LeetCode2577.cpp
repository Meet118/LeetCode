class Solution {
public:
    int n, m;

    struct Node {
        int x, y, ti;
        bool operator < (const Node a) const {
            return ti > a.ti;
        }
    };

    vector<vector<int>> f = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int minimumTime(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        priority_queue<Node> q;
        q.push({0, 0, 0});
        vector<vector<int>> d(n, vector<int>(m, -1));
        while (q.size()) {
            auto t = q.top();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + f[i][0], y = t.y + f[i][1];
                if (x < 0 || x >= n || y < 0 || y >= m || d[x][y] != -1) continue;
                if (t.ti + 1 >= grid[x][y]) {
                    d[x][y] = t.ti + 1;
                } else {
                    if ((grid[x][y] - t.ti) % 2 == 0)
                        d[x][y] = grid[x][y] + 1;
                    else
                        d[x][y] = grid[x][y];
                }
                q.push({x, y, d[x][y]});
            }
        }
        return d[n - 1][m - 1];
    }
};
