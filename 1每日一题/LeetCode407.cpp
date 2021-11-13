class Solution {
public:
    struct Cell {
        int h, x, y;
        bool operator< (const Cell& t) const {
            return h > t.h;
        }
    };

    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();

        priority_queue<Cell> q;
        vector<vector<int>> st(n, vector<int>(m));
        for (int i = 0; i < m; i ++ ) {
            st[0][i] = st[n - 1][i] = 1;
            q.push({h[0][i], 0, i});
            q.push({h[n - 1][i], n - 1, i});
        }
        for (int i = 1; i < n - 1; i ++ ) {
            st[i][0] = st[i][m - 1] = 1;
            q.push({h[i][0], i, 0});
            q.push({h[i][m - 1], i, m - 1});
        }
        vector<int> fx = {0, 0, 1, -1}, fy = {1, -1, 0, 0};
        int ans = 0;
        while (q.size()) {
            auto t = q.top();
            q.pop();
            ans += t.h - h[t.x][t.y];
            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + fx[i], y = t.y + fy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || st[x][y])
                    continue;
                q.push({max(t.h, h[x][y]), x, y});
                st[x][y] = 1;
            }
        }
        return ans;
    }
};