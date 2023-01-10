class Solution {
public:
    unordered_set<string> se;
    int k;
    string ans;

    void dfs(string u) {
        for (int i = 0; i < k; i ++ ) {
            auto s = u + to_string(i);
            if (!se.count(s)) {
                se.insert(s);
                dfs(s.substr(1));
                ans += to_string(i);
            }
        }
    }

    string crackSafe(int n, int _k) {
        k = _k;
        string st = string(n - 1, '0');
        dfs(st);
        return ans + st;
    }
};
