const int N = 100010;

class Solution {
public:
    typedef long long ll;

    vector<vector<int>> g;
    vector<int> p;
    ll d1[N], d2[N], up[N], pa[N]; //分别表示向下最远，向下第二远，向上最远，向下最远的路径对应的子节点
    int n;
    
    void dfs_d(int u, int fa) { //向下搜索（根节点的反方向）
        for (int i : g[u]) {
            if (i != fa) {
                dfs_d(i, u);
                ll d = d1[i] + p[u];
                if (d > d1[u]) {
                    d2[u] = d1[u];
                    d1[u] = d;
                    pa[u] = i;
                }
                else if (d > d2[u]) d2[u] = d;
            }
        }
    }
    
    void dfs_u(int u, int fa) { //向上搜索（根节点的方向）
        for (int i : g[u]) {
            if (i != fa) {
                if (pa[u] == i) up[i] = max(up[u], d2[u]) + p[i];
                else up[i] = max(up[u], d1[u]) + p[i];
                dfs_u(i, u);
            }
        }
    }
    
    long long maxOutput(int _n, vector<vector<int>>& edges, vector<int>& price) {
        n = _n;
        g.resize(n);
        p = price;
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i ++ ) {
            d1[i] = up[i] = p[i];
        }
        dfs_d(0, -1);
        dfs_u(0, -1);
        ll ans = 0;
        for (int i = 0; i < n; i ++ ) {
            ll x = max(d1[i], up[i]);
            ans = max(ans, x - p[i]);
        }
        return ans;
    }
};

