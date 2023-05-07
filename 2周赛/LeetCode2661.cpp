class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<unordered_set<int>> row(n), col(m);
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                mp[mat[i][j]] = {i, j};
            }
        for (int i = 0; i < arr.size(); i ++ ) {
            int x = mp[arr[i]].first, y = mp[arr[i]].second;
            row[x].insert(y);
            col[y].insert(x);
            if (row[x].size() == m || col[y].size() == n)
                return i;
        }
        return -1;
    }
};

