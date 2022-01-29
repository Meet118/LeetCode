class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> f(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (isWater[i][j] == 1)
                    q.push({i, j}), f[i][j] = 0;
            }

        vector<int> fx = {0, 0, 1, -1}, fy = {1, -1, 0, 0};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int x = t.first + fx[i], y = t.second + fy[i];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if (f[x][y] == -1) {
                    f[x][y] = f[t.first][t.second] + 1;
                    q.push({x, y});
                }
            }
        }
        return f;
    }
};
