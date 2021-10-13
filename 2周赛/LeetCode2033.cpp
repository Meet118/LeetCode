class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> a;
        int ming = 1e9;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                ming = min(ming, grid[i][j]);
        
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if ((grid[i][j] - ming) % x != 0)
                    return -1;
                a.push_back(grid[i][j] - ming);
            }
        
        sort(a.begin(), a.end());
        int si = a.size();
        int mid = a[si / 2], ans = 0;
        for (int i : a)
            ans += abs(mid - i) / x;
        
        return ans;
    }
};