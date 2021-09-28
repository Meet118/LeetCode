//dp 分情况讨论
const int mod = 1e9 + 7;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<long long> f(n + 1);
        s = ' ' + s;
        f[0] = 1;

        for (int i = 1; i <= n; i ++ ) {
            if (s[i] == '*') {
                f[i] += f[i - 1] * 9;
                if (i > 1) {
                    if (s[i - 1] == '1')
                        f[i] += f[i - 2] * 9;
                    if (s[i - 1] == '2')
                        f[i] += f[i - 2] * 6;
                    if (s[i - 1] == '*')
                        f[i] += f[i - 2] * 15;
                }
            }
            else {
                int x = s[i] - '0';
                if (x != 0)
                    f[i] += f[i - 1];
                if (i > 1) {
                    if (s[i - 1] == '1')
                        f[i] += f[i - 2];
                    if (s[i - 1] == '*') {
                        if (x >= 0 && x <= 6)
                            f[i] += f[i - 2] * 2;
                        else
                            f[i] += f[i - 2];
                    }
                    if (s[i - 1] == '2' && x <= 6 && x >= 0)
                        f[i] += f[i - 2];
                }
            }
            f[i] %= mod;
        }
        return f[n];
    }
};