class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> f(n);

        if (s[0] == '0') //初始位置为0无法解码
            return 0;
        f[0] = 1;

        for (int i = 1; i < n; i ++ ) {
            int x = s[i] - '0';
            int la = s[i - 1] - '0';
            int two = la * 10 + x;
            
            if (x >= 1 && x <= 9)
                f[i] += f[i - 1];
            if (i > 2 && two >= 10 && two <= 26)
                f[i] += f[i - 2];
            else if (two >= 10 && two <= 26)
                f[i] += 1;
        }

        return f[n - 1];
    }
};