class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && k % 2) return -1;
        int ans = 0;
        for (int i = 0; i + 1 < k && i < n; i ++ )
            ans = max(ans, nums[i]);
        if (k < n)
            ans = max(ans, nums[k]);
        return ans;
    }
};
