class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, a = 0;
        int n = nums.size();
        for (int i = 0; i < n; i ++ ) {
            sum += nums[i] * i;
            a += nums[i];
        }
        int ans = sum;
        for (int i = 1; i < n; i ++ ) {
            int res = sum + a - nums[n - i] * n;
            sum = res;
            ans = max(ans, res);
        }
        return ans;
    }
};
