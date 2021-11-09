class Solution {
public:
    int ans;
    vector<vector<pair<int, int>>> g;
    vector<int> v;
    
    void dfs(int u, int time, int sum, int maxTime) {
        if (time > maxTime)
            return;
        if (u == 0) {
            ans = max(ans, sum);
        }
        for (int i = 0; i < g[u].size(); i ++ ) {
            int t = v[g[u][i].first];
            v[g[u][i].first] = 0;
            dfs(g[u][i].first, time + g[u][i].second, sum + t, maxTime);
            v[g[u][i].first] = t;
        }
    }
    
    
    int maximalPathQuality(vector<int>& _v, vector<vector<int>>& e, int maxTime) {
        int n = _v.size();
        v = _v;
        ans = v[0];
        g.resize(n, vector<pair<int, int>>());
        for (auto i : e) {
            g[i[0]].push_back({i[1], i[2]});
            g[i[1]].push_back({i[0], i[2]});
        }
        
        dfs(0, 0, 0, maxTime);
        
        return ans;
    }
};
