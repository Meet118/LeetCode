class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = 1e9;
        for (int x : nums)
            m = min(m, x);
        int ans = 0;
        for (int x : nums)
            ans += (x - m);
        return ans;
    }
};