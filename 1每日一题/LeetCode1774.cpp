class Solution {
public:
    int ans = 0, min_cost = 1e9;
    int n;

    void dfs(int u, int sum, vector<int>& a, int target) {
        if (abs(sum - target) < min_cost) {
            min_cost = abs(sum - target);
            ans = sum;
        } else if (abs(sum - target) == min_cost && sum < ans) {
            ans = sum;
        }
        if (sum > target) return; //剪枝
        if (n == u) return;
        dfs(u + 1, sum, a, target);
        dfs(u + 1, sum + a[u], a, target);
        dfs(u + 1, sum + a[u] * 2, a, target);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        n = toppingCosts.size();
        for (int x : baseCosts) {
            dfs(0, x, toppingCosts, target);
        }
        return ans;
    }
};
