typedef long long ll;
class Solution {
public:
    int mod = 1e9 + 7;

    int countVowelPermutation(int n) {
        vector<vector<int>> f(2, vector<int>(5));
        int cur = 1, la = 0;
        for (int i = 0; i < 5; i ++ )
            f[la][i] = 1;
        for (int i = 2; i <= n; i ++ ) {
            f[cur][0] = ((ll)f[la][1] + f[la][2] + f[la][4]) % mod;
            f[cur][1] = ((ll)f[la][0] + f[la][2]) % mod;
            f[cur][2] = ((ll)f[la][1] + f[la][3]) % mod;
            f[cur][3] = f[la][2] % mod;
            f[cur][4] = ((ll)f[la][2] + f[la][3]) % mod;
            la = 1 - la;
            cur = 1 - cur;
        }
        int ans = 0;
        for (int i = 0; i < 5; i ++ )
            ans = (ans + f[la][i]) % mod;
        return ans;
    }
};
