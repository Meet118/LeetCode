class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> a;
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int m = p.size();
        for (int x : nums) {
            bool f = true;
            for (int i = 0; i < m; i ++ ) {
                if (x % (p[i] * p[i]) == 0) f = false;
            }
            if (f) a.push_back(x);
        }
        int n = a.size();
        vector<vector<int>> f(n + 1, vector<int>(1 << m));
        f[0][0] = 1;
        const int mod = 1e9 + 7;
        for (int i = 1; i <= n; i ++ ) {
            int y = 0;
                for (int k = 0; k < m; k ++ )
                    if (a[i - 1] % p[k] == 0)
                        y |= (1 << k);
            for (int j = 0; j < (1 << m); j ++ ) {
                // 不选当前数
                f[i][j] = f[i - 1][j];
                if ((j | y) == j) {
                    // 选当前数
                    f[i][j] = (f[i][j] + f[i - 1][j - y]) % mod;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < (1 << m); j ++ )
            ans = (ans + f[n][j]) % mod;
        ans = (ans - 1 + mod) % mod;
        return ans;
    }
};

