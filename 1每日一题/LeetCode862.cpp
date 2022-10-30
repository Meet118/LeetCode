class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> s(1, 0);
        int n = nums.size();
        for (int i = 0; i < n; i ++ ) {
            s.push_back(s[i] + nums[i]);
        }

        int ans = 1e9;
        vector<int> q(n + 1);
        int hh = 0, tt = -1;
        q[ ++ tt] = 0;
        // 判断区间j+1~i
        for (int i = 1; i <= n; i ++ ) {
            while (hh <= tt && s[q[tt]] >= s[i]) tt -- ;
            while (hh <= tt && s[q[hh]] + k <= s[i]) {
                ans = min(ans, i - q[hh]);
                hh ++ ;
            }
            q[ ++ tt] = i;
        }
        return ans == 1e9 ? -1 : ans;
    }
};
