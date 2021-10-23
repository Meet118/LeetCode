class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> g(n, vector<int>(0));
        
        for (auto i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> d(n, 1e9);
        d[0] = 0;
        queue<int> q;
        q.push(0);
        while (q.size()) {
            int t = q.front();
            q.pop();
            for (int i = 0; i < g[t].size(); i ++ ) {
                int j = g[t][i];
                if (d[j] == 1e9) {
                    d[j] = d[t] + 1;
                    q.push(j);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i ++ ) {
            int res = d[i] * 2;
         	//若周期大于第一个信息收到回应的时间
            if (p[i] < res) { //求最后一个发出信息的时间
                if (res % p[i] == 0) //能整除则少一个周期
                    res += (res / p[i] - 1) * p[i];
                else
                    res += (res / p[i]) * p[i];
            }
            //耗费时间最长的完成则空闲
            ans = max(ans, res);
        }
        return ans + 1; //从第0秒开始
    }
};
