typedef pair<int, int> PII;

#define x first
#define y second

class Solution {
public:
    vector<vector<PII>> g;
    vector<int> d;
    int n;

    void dijkstra() {
        d[0] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({0, 0});
        vector<bool> st(n);
        while (q.size()) {
            auto t = q.top();
            q.pop();
            int w = t.x, v = t.y;
            if (st[v]) continue;
            st[v] = true;
            for (int i = 0; i < g[v].size(); i ++ ) {
                PII j = g[v][i];
                if (d[j.x] > w + j.y) {
                    d[j.x] = w + j.y;
                    q.push({d[j.x], j.x});
                }
            }
        }
    }

    void spfa() {
        d[0] = 0;
        vector<bool> st(n);
        queue<int> q;
        q.push(0);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            st[t] = false;
            for (auto i : g[t]) {
                if (d[i.x] > d[t] + i.y) {
                    d[i.x] = d[t] + i.y;
                    if (!st[i.x]) {
                        st[i.x] = true;
                        q.push(i.x);
                    }
                }
            }
        }
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int _n) {
        n = _n;
        g.resize(n);
        d.resize(n, 0x3f3f3f3f);
        for (auto& e : edges) {
            g[e[0]].push_back({e[1], e[2] + 1});
            g[e[1]].push_back({e[0], e[2] + 1});
        }
        spfa();
        // dijkstra();
        int ans = 0;
        for (auto& e : edges) {
            int a = 0, b = 0;
            if (d[e[0]] <= maxMoves) a = maxMoves - d[e[0]];
            if (d[e[1]] <= maxMoves) b = maxMoves - d[e[1]];
            ans += min(a + b, e[2]);
        }
        for (int i = 0; i < n; i ++ ) {
            if (d[i] <= maxMoves) ans ++ ;
        }
        return ans;
    }
};
