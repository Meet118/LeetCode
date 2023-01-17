class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> b;
        for (int x : nums) {
            auto t = get(x);
            b.push_back(x - t);
        }
        int ans = 0;
        const int mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for (int x : b) {
            ans = ((long long)ans + mp[x]) % mod;
            mp[x] ++ ;
        }
        return ans;
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};
