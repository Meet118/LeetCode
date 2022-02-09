class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i ++ ) {
            ans += mp[nums[i] + k] + mp[nums[i] - k];
            mp[nums[i]] ++ ;
        }
        return ans;
    }
};
