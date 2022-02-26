class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mi = 1e9;
        int ans = 0;
        for (int i : nums) {
            mi = min(mi, i);
            ans = max(ans, i - mi);
        }
        return ans == 0 ? -1 : ans;
    }
};
