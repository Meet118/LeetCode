class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
        vector<int> dis(n + 1, 0);
        vector<int> d(n + 1);
        vector<vector<int>> g(n + 1, vector<int>());
        
        for (auto i : r) {
            d[i[1]] ++ ;
            g[i[0]].push_back(i[1]);
        }
        vector<int> st(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i ++ ) {
            if (d[i] == 0) {
                q.push(i);
                dis[i] = time[i - 1];
                st[i] = 1;
            }
        }
        
        while (q.size()) {
            int t = q.front();
            q.pop();
            st[t] = 0;
            for (int i = 0; i < g[t].size(); i ++ ) {
                int j = g[t][i];
                if (dis[j] < dis[t] + time[j - 1]) {
                    if(st[j] == 0) {
                        q.push(j);
                        st[j] = 1;
                    }
                    dis[j] = dis[t] + time[j - 1];
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i ++ )
            ans = max(ans, dis[i]);
        
        return ans;
    }
};
