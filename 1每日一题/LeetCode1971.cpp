class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        p.resize(n);
        for (int i = 0; i < n; i ++ ) p[i] = i;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            p[find(a)] = find(b);
        }
        return find(source) == find(destination);
    }
};
