class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i ++ ) {
            vector<int> cnt(26);
            for (int j = i; j < n; j ++ ) {
                cnt[s[j] - 'a'] ++ ;
                int maxCnt = 0, minCnt = 500;
                for (int k = 0; k < 26; k ++ ) {
                    maxCnt = max(maxCnt, cnt[k]);
                    if (cnt[k] != 0)
                        minCnt = min(minCnt, cnt[k]);
                }
                ans += maxCnt - minCnt;
            }
        }
        return ans;
    }
};
