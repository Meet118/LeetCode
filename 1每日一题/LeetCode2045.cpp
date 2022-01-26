class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1);
        vector<int> d1(n + 1, -1), d2(n + 1, -1);
        for (auto i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        queue<pair<int, int>> q;
        q.push({1, 0});
        d1[1] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            int node = t.first;
            int used_time = t.second;
            for (auto i : g[node]) {
                if (used_time / change % 2 == 1)
                    used_time = (used_time / change + 1) * change;
                int s = used_time + time;
                if (d1[i] == -1) {
                    d1[i] = s;
                    q.push({i, d1[i]});
                }
                else if (d2[i] == -1 && d1[i] != s) { //第二小的不存在且不和第一小的相等（严格小于）
                    d2[i] = s;
                    q.push({i, d2[i]});
                }
            }
        }
        return d2[n];
    }
};
