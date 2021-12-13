class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int startPos, int k) {
        int n = f.size();
        int N = 2 * 1e5 + 10;
        vector<int> s(N + 1);
        int j = 0;
        for (int i = 1; i <= N; i ++ ) {
            s[i] = s[i - 1];
            if (j < n && i == f[j][0] + 1)
                s[i] = s[i - 1] + f[j][1], j ++ ;
        }
        
        int ans = 0;
        startPos ++ ;
        for (int i = 0; i <= k; i ++ ) {
            int l = max(1, startPos - i); //先向左走i
            int r = min(N, startPos - i + (k - i)); //再向右走k - i
            if (r < startPos) r = startPos;
            if (l > startPos) l = startPos;
            ans = max(ans, s[r] - s[l - 1]);
            
            r = min(N, startPos + i); //先向右走i
            l = max(1, startPos + i - (k - i)); //再向左走k - i
            if (r < startPos) r = startPos;
            if (l > startPos) l = startPos;
            ans = max(ans, s[r] - s[l - 1]);
        }
        return ans;
    }
};

