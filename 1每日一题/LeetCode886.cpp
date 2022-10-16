class Solution {
public:
    vector<vector<int>> g;
    vector<int> color;

    bool dfs(int u, int c) {
        color[u] = c;
        for (int i : g[u]) {
            if (color[i]) {
                if (color[i] == c) return false;
            } else if (!dfs(i, 3 - c)) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        g.resize(n + 1);
        color.resize(n + 1);
        for (auto e : dislikes) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 1; i <= n; i ++ ) {
            if (color[i] == 0) {
                if (!dfs(i, 1))
                    return false;
            }
        }
        return true;
    }
};
