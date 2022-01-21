class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> g;
        int n = arr.size();
        for (int i = 0; i < n; i ++ ) {
            g[arr[i]].push_back(i);
        }
        unordered_set<int> se;
        queue<int> q;
        q.push(0);
        vector<int> f(n, -1);
        f[0] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t && f[t - 1] == -1) {
                f[t - 1] = f[t] + 1;
                q.push(t - 1);
            }
            if (t + 1 < n && f[t + 1] == -1) {
                f[t + 1] = f[t] + 1;
                q.push(t + 1);
            }
            if (!se.count(arr[t])) {
                for (int i : g[arr[t]])
                    if (i != t && f[i] == -1) {
                        f[i] = f[t] + 1;
                        q.push(i);
                    }
                se.insert(arr[t]);
            }
        }

        return f[n - 1];
    }
};
