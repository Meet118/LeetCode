class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> f(26);
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i ++ ) {
            int t = 1;
            for (int j = 0; j < 26; j ++ ) {
                t = (t + f[j]) % mod;
            }
            f[s[i] - 'a'] = t;
        }
        int ans = 0;
        for (int i = 0; i < 26; i ++ )
            ans = (ans + f[i]) % mod;
        return ans;
    }
};

