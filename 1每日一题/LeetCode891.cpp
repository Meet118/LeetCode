class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        const int mod = 1e9 + 7;
        vector<int> p(n);
        p[0] = 1;
        for (int i = 1; i < n; i ++ ) p[i] = p[i - 1] * 2 % mod;
        for (int i = 0; i < n; i ++ ) {
            ans = (ans + (long long)nums[i] * p[i] % mod) % mod;
            ans = (ans - (long long)nums[i] * p[n - i - 1] % mod) % mod;
        }

        return ans;
    }
};
