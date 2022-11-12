typedef long long ll;
class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;   
        vector<vector<ll>> f(n + 1, vector<ll>(4));
        f[0][3] = 1;
        
        for (int i = 1; i <= n; i ++ ) {
            f[i][0] = f[i - 1][3];
            f[i][1] = (f[i - 1][0] + f[i - 1][2]) % mod;
            f[i][2] = (f[i - 1][0] + f[i - 1][1]) % mod;
            f[i][3] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][2] + f[i - 1][3]) % mod;
        }

        return f[n][3];
    }
};
