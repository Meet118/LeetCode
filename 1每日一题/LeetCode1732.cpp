class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int cur = 0;
        for (int x : gain) {
            cur += x;
            ans = max(ans, cur);
        }
        return ans;
    }
};
