class Solution {
public:
    int waysToReachTarget(int n, vector<vector<int>>& types) {
        int ans = 0;
        int m = types.size();
        const int mod = 1e9 + 7;
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 0; j <= n; j ++ ) {
                f[i][j] = f[i - 1][j]; //不选
                for (int k = 1; k <= types[i - 1][0]; k ++ ) { //选
                    if (j >= k * types[i - 1][1])
                        f[i][j] = (f[i][j] + f[i - 1][j - k * types[i - 1][1]]) % mod;
                }
            }
        }
        return f[m][n];
    }
};

