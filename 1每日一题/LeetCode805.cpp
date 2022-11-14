class Solution {
public:
    unordered_multiset<int> se;
    vector<int> nums;

    void dfs1(int u, int n, int sum) {
        if (u == n) {
            se.insert(sum);
            return;
        }
        dfs1(u + 1, n, sum + nums[u]);
        dfs1(u + 1, n, sum);
    }

    bool dfs2(int u, int n, int sum, int cnt, int all) {
        if (u == n) {
            if (cnt && cnt < all && se.count(-sum))
                return true;
            return false;
        }
        if (dfs2(u + 1, n, sum + nums[u], cnt + 1, all)) return true;
        if (dfs2(u + 1, n, sum, cnt, all)) return true;
        return false;
    }

    bool splitArraySameAverage(vector<int>& _nums) {
        nums = _nums;
        int sum = 0;
        int n = nums.size();
        int m = n / 2;
        for (int x : nums) sum += x;
        for (int i = 0; i < n; i ++ ) nums[i] = (nums[i] * n) - sum;
        dfs1(0, m, 0);
        se.erase(se.find(0));
        if (se.count(0)) return true;
        return dfs2(m, n, 0, 0, n - m);
    }
};
