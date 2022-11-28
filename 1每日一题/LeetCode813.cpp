class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> f(n + 1, vector<double>(k + 1, -1e9));

        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + nums[i - 1];
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int x = 0; x < i; x++) {
                    f[i][j] = max(f[i][j], f[x][j - 1] + (double) (s[i] - s[x]) / (i - x));
                }
            }
        }

        return f[n][k];
    }
};
