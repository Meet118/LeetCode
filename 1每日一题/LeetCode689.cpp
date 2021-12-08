class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(4));
        vector<int> s(n + 1);
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; i ++ )
            s[i] = s[i - 1] + nums[i];
        
        int cur = 0, m = 0;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= 3; j ++ ) {
                f[i][j] = f[i - 1][j]; //不选当前数
                if (i - k >= 0) { //选当前数
                    int sum = s[i] - s[i - k];
                    f[i][j] = max(f[i][j], f[i - k][j - 1] + sum);
                }
                if (j == 3 && f[i][j] > m) {
                    cur = i;
                    m = f[i][j];
                }
            }
        //求方案
        vector<int> ans(3);
        ans[2] = cur - k;
        for (int j = 2; j; j -- ) {
            int sum = s[cur] - s[cur - k];
            for (int i = 1; i <= n; i ++ ) {
                if (f[i][j] + sum == m) {
                    cur = i;
                    ans[j - 1] = cur - k;
                    m -= sum;
                    break;
                }
            }
        }
        return ans;
    }
};
