class Solution {
public:
    int mod = 1e9 + 7;

    int kInversePairs(int n, int k) {
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            int t = 0;
            for (int j = 0; j <= k; j ++ ) {
                t = (t + f[i - 1][j]) % mod;
                if (j >= i)
                    t = (t - f[i - 1][j - i]) % mod;
                f[i][j] = t;
            }
        }
        return (f[n][k] + mod) % mod;
    }
};
