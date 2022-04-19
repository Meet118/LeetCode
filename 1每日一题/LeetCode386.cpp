class Solution {
public:
    vector<int> ans;
    int n;

    void dfs(int u) {
        if (u > n) return;
        ans.push_back(u);
        for (int i = 0; i < 10; i ++ )
            dfs(u * 10 + i);
    }

    vector<int> lexicalOrder(int _n) {
        n = _n;
        for (int i = 1; i < 10; i ++ )
            dfs(i);
        return ans;
    }
};
