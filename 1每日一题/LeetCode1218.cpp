class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int ans = 1;
        for (int x : arr) {
            if (mp.count(x - difference)) {
                ans = max(ans, mp[x - difference] + 1);
                mp[x] = mp[x - difference] + 1;
            }
            else
                mp[x] = 1;
        }
        return ans;
    }
};