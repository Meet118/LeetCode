class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n); //记录以i结尾最长上升子序列的长度
        vector<int> g(n); //记录以i结尾最长上升子序列的个数
        int maxlen = 0;
        for (int i = 0; i < n; i ++ ) {
            f[i] = 1;
            g[i] = 1;
            for (int j = 0; j < i; j ++ )
                if (nums[j] < nums[i]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    }
                    else if (f[i] == f[j] + 1) {
                        g[i] += g[j];
                    }
                }
            maxlen = max(maxlen, f[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i ++ )
            if (f[i] == maxlen)
                ans += g[i];
        
        return ans;
    }
};