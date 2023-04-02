class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        vector<vector<int>> g; //记录图
        int n = coins.size();
        g.resize(n);
        vector<int> d(n); //记录入度
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            d[e[0]] ++ ;
            d[e[1]] ++ ;
        }
        queue<int> q;
        for (int i = 0; i < n; i ++ ) {
            if (coins[i] == 0 && d[i] == 1)
                q.push(i);
        }
        while (q.size()) {
            auto t = q.front();
            d[t] = 0;
            q.pop();
            for (auto i : g[t]) {
                d[i] -- ;
                if (d[i] == 1 && coins[i] == 0)
                    q.push(i);
            }
        }
        vector<int> a;
        for (int i = 0; i < n; i ++ ) {
            if (coins[i] == 1 && d[i] == 1) //叶节点且含有金币
                a.push_back(i);
        }
        for (int t : a) {
            d[t] = 0;
            for (auto i : g[t]) {
                d[i] -- ;
                if (d[i] == 1) //邻居若为叶节点，也可去除
                    d[i] -- ;
            }
        }
        int cnt = 0; //仍在图中的节点数量
        for (int i = 0; i < n; i ++ )
            if (d[i] > 0) cnt ++ ;
        return max((cnt - 1) * 2, 0);
    }
};

