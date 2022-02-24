class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans;
        for (int i = 0; i < m; i ++ ) {
            int x = 0, y = i;
            bool f = true;
            while (x != n) {
                if (grid[x][y] == 1) {
                    x ++ , y ++ ;
                    if (y == m || grid[x - 1][y] == -1) {
                        f = false;
                        break;
                    }
                }
                else if (grid[x][y] == -1) {
                    x ++ , y -- ;
                    if (y == -1 || grid[x - 1][y] == 1) {
                        f = false;
                        break;
                    }         
                }        
            }
            if (!f)
                y = -1;
            ans.push_back(y);
        }
        return ans;
    }
};
