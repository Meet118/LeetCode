class Solution {
public:
    typedef long long ll;
    
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] ++ ;
        ll ans = 0;
        for (int i = 0, s = 0; i < n; i ++ ) {
            s ^= nums[i];
            ans += mp[s];
            mp[s] ++ ;
        }
        return ans;
    }
};

