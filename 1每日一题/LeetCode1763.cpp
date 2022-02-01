class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";
        int m = 0;
        for (int i = 0; i < n; i ++ ) {
            int l = 0, u = 0;
            for (int j = i; j < n; j ++ ) {
                if (islower(s[j]))
                    l |= (1 << (s[j] - 'a'));
                else
                    u |= (1 << (s[j] - 'A'));

                if (l == u && j - i + 1 > m) {
                    ans = s.substr(i, j - i + 1);
                    m = j - i + 1;
                }
            }
        }
        return ans;
    }
};
