class Solution {
public:
    int maxRepeating(string a, string b) {
        int n = a.size(), m = b.size();
        a = ' ' + a, b = ' ' + b;
        vector<int> ne(m + 1);
        for (int i = 2, j = 0; i <= m; i ++ ) {
            while (j && b[j + 1] != b[i]) j = ne[j];
            if (b[i] == b[j + 1]) j ++ ;
            ne[i] = j;
        }
        vector<int> f(n + 1);
        for (int i = 1, j = 0; i <= n; i ++ ) {
            while (j && a[i] != b[j + 1]) j = ne[j];
            if (a[i] == b[j + 1]) j ++ ;
            if (j == m) {
                f[i] = f[i - m] + 1;
            }
        }
        int ans = 0;
        for (int x : f) {
            ans = max(ans, x);
        }
        return ans;
    }
};
