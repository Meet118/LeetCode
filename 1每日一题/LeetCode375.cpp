class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 1e9));
        for (int len = 1; len <= n; len ++ ) 
            for (int l = 1; l + len - 1 <= n; l ++ ) {
                int r = l + len - 1;
                for (int k = l; k <= r; k ++ ) {
                    int t = 0;
                    if (k - 1 >= l)
                        t = max(t, f[l][k - 1] + k);
                    if (k + 1 <= r)
                        t = max(t, f[k + 1][r] + k);
                    f[l][r] = min(f[l][r], t);
                }
            }
        return f[1][n];
    }
};