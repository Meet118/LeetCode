class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        int lsum = 0, rsum = sum;
        int ans = 1e6;
        for (int l = -1, r = 0; l < n; l ++ ) {
            if (l != -1) lsum += nums[l];
            while (l >= r || r < n && lsum + rsum > x) {
                rsum -= nums[r];
                r ++ ;
            }
            if (lsum + rsum == x)
                ans = min(ans, n - r + l + 1);
        }

        return ans == 1e6 ? -1 : ans;
    }
};
