class Solution {
public:
    vector<vector<int>> g;
    vector<int> up, d1, d2, p;

    void dfs_down(int u, int fa) {
        for (int i : g[u]) {
            if (i == fa) continue;
            dfs_down(i, u);
            if (d1[i] + 1 > d1[u]) {
                d2[u] = d1[u];
                d1[u] = d1[i] + 1;
                p[u] = i;
            }
            else if (d1[i] + 1 > d2[u])
                d2[u] = d1[i] + 1;
        }
    }

    void dfs_up(int u, int fa) {
        for (int i : g[u]) {
            if (i == fa) continue;
            if (i == p[u]) up[i] = max(up[u], d2[u]) + 1;
            else up[i] = max(up[u], d1[u]) + 1;
            dfs_up(i, u);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g.resize(n);
        up.resize(n);
        d1.resize(n);
        d2.resize(n);
        p.resize(n);
        for (auto i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs_down(0, -1);
        dfs_up(0, -1);
        vector<int> ans;
        int m = 1e9;
        for (int i = 0; i <= n - 1; i ++ )
            m = min(m, max(up[i], d1[i]));
        for (int i = 0; i <= n - 1; i ++ )
            if (max(up[i], d1[i]) == m)
                ans.push_back(i);
        return ans;
    }
};
