class Solution {
public:
    vector<int> d;
    
    void dfs(vector<vector<int>>& g, int cnt, int u) {
        if (g[u].size() == 0)
            d[u] == 0;
        if (g[u].size() > 0) {
            dfs(g, cnt + 1, g[u][0]);
            d[u] += d[g[u][0]] + 1;
        }
        if (g[u].size() > 1) {
            dfs(g, cnt + 1, g[u][1]);
            d[u] += d[g[u][1]] + 1;
        }
    }
    
    int countHighestScoreNodes(vector<int>& p) {
        int n = p.size();
        d.resize(n);
        vector<vector<int>> g(n, vector<int>(0));
        
        for (int i = 1; i < n; i ++ )
            g[p[i]].push_back(i);
        
        dfs(g, 0, 0);
        vector<int> l(n), r(n);
        vector<long long> b(n);
        long long m = 0;
        for (int i = 0; i < n; i ++ ) {
            long long t = 1;

            if (g[i].size() > 0) {
                l[i] = d[g[i][0]] + 1;
                t *= (long long)l[i];
            }
            if (g[i].size() > 1) {
                r[i] = d[g[i][1]] + 1;
                t *= r[i];
            }
            if (n - l[i] - r[i] - 1 != 0)
                t *= (n - l[i] - r[i] - 1ll);
            b[i] = t;
            m = max(m, t);
        }
        
        int ans = 0;
        for (long long i : b)
            if (i == m)
                ans ++ ;
        return ans;
    }
};
