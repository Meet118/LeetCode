class Solution {
public:
    vector<vector<int>> g;
    long maxs = 0;
    int cnt = 0;
    int n;

    int dfs(int u) {
        long s = 1;
        int size = n - 1;
        for (int i : g[u]) {
            int t = dfs(i);
            s *= t;
            size -= t;
        }
        if (u != 0)
            s *= size;
        if (s == maxs)
            cnt ++ ;
        else if (s > maxs) {
            maxs = s;
            cnt = 1;
        }
        return n - size;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        g.resize(n);
        for (int i = 0; i < n; i ++ ) {
            if (parents[i] != -1)
                g[parents[i]].push_back(i);
        }
        dfs(0);
        return cnt;
    }
};
