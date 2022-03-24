class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                int t = 0;
                int cnt = 0;
                for (int x = i - 1; x <= i + 1; x ++ )
                    for (int y = j - 1; y <= j + 1; y ++ ) {
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            cnt ++ ;
                            t += img[x][y];
                        }
                    }
                ans[i][j] = t / cnt;
            }
        return ans;
    }
};
