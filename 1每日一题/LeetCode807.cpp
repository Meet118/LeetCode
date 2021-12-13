class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> r(n), c(n);
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                r[i] = max(r[i], grid[i][j]);
                c[i] = max(c[i], grid[j][i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ ) {
                int t = min(r[i], c[j]);
                ans += t - grid[i][j];
            }

        return ans;
    }
};
