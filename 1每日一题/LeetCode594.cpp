class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for (int x : nums)
            mp[x] ++ ;
        int ans = 0;
        for (auto& [k, v] : mp) {
            if (mp.count(k - 1))
                ans = max(ans, mp[k] + mp[k - 1]);
        }
        return ans;
    }
};
