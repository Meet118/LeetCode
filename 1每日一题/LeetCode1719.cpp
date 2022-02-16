class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        int m = pairs.size();
        //记录某个节点的所有祖先或后代节点
        unordered_map<int, unordered_set<int>> g;
        for (auto &i : pairs) {
            g[i[0]].insert(i[1]);
            g[i[1]].insert(i[0]);
        }
        //点的数量
        int n = g.size();
        //寻找根节点
        int root = -1;
        for (auto &[k, b] : g)
            //根节点的后代节点数量必为n - 1
            if (b.size() == n - 1) {
                root = k;
                break;
            }
        if (root == -1)
            return 0;
        int ans = 1;
        //遍历所有节点
        for (auto &[k, v] : g) {
            if (k == root)
                continue;
            int p = -1; //寻找父节点
            int pd = 1e9; //父节点的度
            int cd = v.size();
            for (auto &i : v) {
                //父节点的度大于等于当前节点的度中最小的一个
                if (g[i].size() >= cd && g[i].size() < pd) {
                    p = i;
                    pd = g[i].size();
                }
            }
            if (p == -1)
                return 0;
            //当前节点的所有祖先或后代节点是父节点的所有祖先或后代节点的子集
            for (auto &i : v) {
                if (i == p)
                    continue;
                if (!g[p].count(i))
                    return 0;
            }
            //父节点和当前节点的所有祖先或后代节点数量相同，说明在一条路径上，可以交换
            if (pd == cd)
                ans = 2;
        }

        return ans;
    }
};
