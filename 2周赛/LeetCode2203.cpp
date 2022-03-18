typedef long long ll;
typedef pair<ll, int> PLI;
class Solution {
public:
    vector<vector<pair<int, int>>> g;
    vector<vector<pair<int, int>>> ug;
    int n;
    
    vector<ll> di(int s, vector<vector<pair<int, int>>> g) {
        vector<ll> d(n, 1e18);
        vector<bool> st(n, false);
        priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
        d[s] = 0;
        heap.push({0, s});
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            int v = t.second;
            ll dis = t.first;
            if (st[v]) continue;
            st[v] = true;
            for (auto i : g[v]) {
                int j = i.first, w = i.second;
                if (d[j] > dis + w) {
                    d[j] = dis + w;
                    heap.push({d[j], j});
                }
            }
        }
        return d;
    }
    
    long long minimumWeight(int _n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        n = _n + 1;
        g.resize(n);
        ug.resize(n);
        
        for (auto i : edges) {
            g[i[0]].push_back({i[1], i[2]});
        }
        for (auto i : edges) {
            ug[i[1]].push_back({i[0], i[2]});
        }
        vector<ll> d1, d2, d3;
        d1 = di(src1, g);
        d2 = di(src2, g);
        d3 = di(dest, ug);
        ll ans = 1e18;
        for (int i = 0; i < n; i ++ ) {
            if (d1[i] != 1e18 && d2[i] != 1e18 && d3[i] != 1e18)
                ans = min(ans, d1[i] + d2[i] + d3[i]);
        }
        return ans == 1e18 ? -1 : ans;
    }
};
