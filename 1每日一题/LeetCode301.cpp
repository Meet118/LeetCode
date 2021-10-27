class Solution {
public:
    vector<string> ans;

    void dfs(string& s, int u, string p, int l, int r, int d) {
        if (d < 0)
            return;
        if (u == s.size()) {
            if (l == 0 && r == 0 && d == 0)
                ans.push_back(p);
            return;
        }
        if (s[u] != '(' && s[u] != ')')
            dfs(s, u + 1, p + s[u], l, r, d);
        else if (s[u] == '(') {
            int k = u + 1;
            while (k < s.size() && s[k] == '(') k ++ ;
            for (int i = 0; i <= k - u; i ++ ) {
                if (l - i >= 0) {
                    dfs(s, k, p + string(k - u - i, '('), l - i, r, d + k - u - i);
                }
            }
        }
        else if (s[u] == ')') {
            int k = u + 1;
            while (k < s.size() && s[k] == ')') k ++ ;
            for (int i = 0; i <= k - u; i ++ ) {
                if (r - i >= 0) {
                    dfs(s, k, p + string(k - u - i, ')'), l, r - i, d - (k - u - i));
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0; //l和r表示当前需要删掉多少个左括号和右括号
        for (char c : s) {
            if (c == '(') l ++ ;
            else if (c == ')') {
                if (l == 0) r ++ ;
                else l -- ;
            }
        }
        dfs(s, 0, "", l, r, 0);
        return ans;
    }
};