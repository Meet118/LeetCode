typedef pair<int, int> PII;
#define x first
#define y second

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<PII> a;
        int n = grid.size();
        a.resize(n * n);
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                a[grid[i][j]] = {i, j};
        if (!(a[0].x == 0 && a[0].y == 0)) return false;
        for (int i = 1; i < n * n; i ++ ) {
            int x1 = a[i].x, y1 = a[i].y, x2 = a[i - 1].x, y2 = a[i - 1].y;
            if (abs(x1 - x2) == 1 && abs(y1 - y2) == 2 || abs(x1 - x2) == 2 && abs(y1 - y2) == 1) continue;
            return false;
        }
        return true;
    }
};

