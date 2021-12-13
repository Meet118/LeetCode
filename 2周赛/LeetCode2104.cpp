class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int l = 0; l < n; l ++ ) {
            int a = nums[l], b = nums[l];
            for (int r = l; r < n; r ++ ) {
                a = min(a, nums[r]);
                b = max(b, nums[r]);
                ans += (long long)(b - a);
            }
        }
        return ans;
    }
};

