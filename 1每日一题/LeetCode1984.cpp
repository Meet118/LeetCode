class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1e9, n = nums.size();
        for (int i = 0; i + k - 1 < n; i ++ ) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
