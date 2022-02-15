class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> r(n, 1e9), c(m);
        vector<int> ans;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                r[i] = min(r[i], matrix[i][j]);
                c[j] = max(c[j], matrix[i][j]);
            }
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (matrix[i][j] == r[i] && matrix[i][j] == c[j])
                    ans.push_back(matrix[i][j]);
            }
        return ans;
    }
};
