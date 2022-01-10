class Solution {
public:
    int n;

    bool isAdditiveNumber(string num) {
        n = num.size();
        for (int a = 1; a <= n; a ++ )
            for (int b = 1; a + b + max(a, b) <= n; b ++ )
                if (dfs(0, a, a, b, num))
                    return true;
        return false;
    }

    bool dfs(int ai, int la, int bi, int lb, string s) {
        if (la > 1 && s[ai] == '0' || lb > 1 && s[bi] == '0')
            return false;
        if (bi + lb == s.size())
            return true;
        int len = max(la, lb);
        if (bi + lb + len - 1 < n && check(s.substr(ai, la), s.substr(bi, lb), s.substr(bi + lb, len)) && dfs(bi, lb, bi + lb, len, s))
            return true;
        if (bi + lb + len < n && check(s.substr(ai, la), s.substr(bi, lb), s.substr(bi + lb, len + 1)) && dfs(bi, lb, bi + lb, len + 1, s))
            return true;
        return false;
    }

    bool check(string a, string b, string c) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string d = "";
        for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i ++ ) {
            if (i < a.size()) t += a[i] - '0';
            if (i < b.size()) t += b[i] - '0';
            d += '0' + t % 10;
            t /= 10;
        }
        reverse(d.begin(), d.end());
        return c == d;
    }
};
