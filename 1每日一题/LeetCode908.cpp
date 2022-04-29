class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int a = nums[0], b = nums[0];
        for (int i : nums)
            a = max(a, i), b = min(b, i);
        int ans = (a - b) - k * 2;
        return ans <= 0 ? 0 : ans;
    }
};
