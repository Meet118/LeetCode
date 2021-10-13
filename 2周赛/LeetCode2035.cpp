class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size() / 2;
        for (int i = 0; i < (1 << n); i ++ ) {
            int z_cnt = 0; //正号个数
            int sum = 0;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1) {
                    sum += nums[j];
                    z_cnt ++ ;
                }
                else
                    sum -= nums[j];
            mp[z_cnt].push_back(sum);
        }
        for (int i = 0; i <= n; i ++ )
            sort(mp[i].begin(), mp[i].end());
        int ans = 1e9;
        for (int i = 0; i < (1 << n); i ++ ) {
            int z_cnt = 0; //正号个数
            int sum = 0;
            for (int j = 0; j < n; j ++ ) {
                if (i >> j & 1) {
                    sum += nums[n + j];
                    z_cnt ++ ;
                }
                else
                    sum -= nums[n + j];
            }
            vector<int>& t = mp[n - z_cnt];
            int pos = lower_bound(t.begin(), t.end(), -sum) - t.begin();
            if (pos < t.size())
                ans = min(ans, abs(t[pos] + sum));
            if (pos > 0)
                ans = min(ans, abs(t[pos - 1] + sum));
        }
        return ans;
    }
};