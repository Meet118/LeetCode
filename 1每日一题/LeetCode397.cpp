class Solution {
public:
    unordered_map<long long, int> f;

    int dp(long long x) {
        if (f.count(x))
            return f[x];
        if (x == 1)
            return 0;
        if (x % 2 == 0)
            f[x] = dp(x / 2) + 1;
        else {
            f[x] = dp(x - 1) + 1;
            // if (x != INT_MAX)
                f[x] = min(f[x], dp(x + 1ll) + 1);
        }
        return f[x];
    }

    int integerReplacement(int n) {
        return dp(n);
    }
};
