class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int ans = 0;
        for (int i = 0; i < m; i ++ ) {
            bool f = false;
            for (int j = 0; j + 1 < n; j ++ )
                if (strs[j][i] > strs[j + 1][i]) {
                    f = true;
                    break;
                }
            if (f)
                ans ++ ;
        }
        return ans;
    }
};
