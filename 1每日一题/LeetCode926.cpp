class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ )
            a[i] = a[i - 1] + s[i - 1] - '0';
        int ans = n - a[n];
        for (int i = 0; i < n; i ++ )
            ans = min(ans, a[i + 1] + (n - i - 1) - (a[n] - a[i + 1]));
        return ans;
    }
};
