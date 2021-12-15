class Solution {
public:
    vector<vector<int>> g;
    vector<int> ans;
    vector<int> quiet;

    void dfs(int u) {
        if (ans[u] != -1)
            return;
        ans[u] = u;
        for (int x : g[u]) {
            dfs(x);
            if (quiet[ans[u]] > quiet[ans[x]])
                ans[u] = ans[x];
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& _quiet) {
        quiet = _quiet;
        int n = quiet.size();
        g.resize(n);
        ans.resize(n, -1);
        for (auto i : richer)
            g[i[1]].push_back(i[0]);
        for (int i = 0; i < n; i ++ )
            dfs(i);

        return ans;
    }
};
