#define x first
#define y second

class Solution {
public:
    typedef pair<int, int> PII;

    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<priority_queue<PII, vector<PII>, greater<PII>>> row(n), col(m);
        vector<vector<int>> d(n, vector<int>(m, -1));
        d[0][0] = 1;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                //从左边来
                while (row[i].size() && row[i].top().y + grid[i][row[i].top().y] < j) {
                    row[i].pop();
                }
                if (row[i].size()) {
                    d[i][j] = d[i][row[i].top().y] + 1;
                }
                //从上面来
                while (col[j].size() && col[j].top().y + grid[col[j].top().y][j] < i) {
                    col[j].pop();
                }
                if (col[j].size()) {
                    if (d[i][j] != -1)
                        d[i][j] = min(d[i][j], d[col[j].top().y][j] + 1);
                    else
                        d[i][j] = d[col[j].top().y][j] + 1;
                }
                if (d[i][j] != -1) {
                    row[i].push({d[i][j], j});
                    col[j].push({d[i][j], i});
                }
            }
        return d[n - 1][m - 1];
    }
};

