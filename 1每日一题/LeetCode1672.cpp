class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto i : accounts) {
            int t = 0;
            for (int j : i)
                t += j;
            ans = max(ans, t);
        }
        return ans;
    }
};
