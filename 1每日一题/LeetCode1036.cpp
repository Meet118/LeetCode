class Solution {
public:
    vector<int> fx = {0, 0, 1, -1}, fy = {1, -1, 0, 0};
    int n = 1e6;
    set<pair<int, int>> b;
    set<pair<int, int>> vis;
    int M = 20000;
    bool f = false;
    vector<int> t;

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for (auto i : blocked)
            b.insert({i[0], i[1]});
        int c1 = 0, c2 = 0;
        t = target;
        dfs(source[0], source[1], 0);
        if (f)
            return true;
        c1 = vis.size();
        vis.clear();
        dfs(target[0], target[1], 1);
        c2 = vis.size();
        return c1 >= M && c2 >= M;
    }

    void dfs(int x, int y, int flag) {
        if (vis.size() >= M)
            return;
        vis.insert({x, y});
        if (flag == 0 && x == t[0] && y == t[1]) {
            f = true;
            return;
        }
        for (int i = 0; i < 4; i ++ ) {
            int xx = x + fx[i], yy = y + fy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n || vis.count({xx, yy}) || b.count({xx, yy}))
                continue;
            dfs(xx, yy, flag);
        }
    }
};
