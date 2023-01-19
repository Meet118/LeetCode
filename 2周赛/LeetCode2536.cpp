class Solution {
public:
    vector<vector<int>> b;
    
    void ins(int x1, int y1, int x2, int y2, int c) {
        b[x1][y1] += c;
        b[x2 + 1][y1] -= c;
        b[x1][y2 + 1] -= c;
        b[x2 + 1][y2 + 1] += c;
    }
    
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        b.resize(n + 2, vector<int>(n + 2));
        for (int i = 0; i < q.size(); i ++ ) {
                ins(q[i][0] + 1, q[i][1] + 1, q[i][2] + 1, q[i][3] + 1, 1);
            }
        vector<vector<int>> a(n, vector<int>(n)); 
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ ) {
                b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
                a[i - 1][j - 1] = b[i][j];
            }
        return a;
    }
};

