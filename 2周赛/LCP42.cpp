/*
记toy xt, yt, t
ring xr, yr
满足条件的toy (xt - xr)^2 + (yt - yr)^2 <= (t - r)^2 && r >= t ---(1)
由于r <= 10
对于每个toy来说 (1)式的范围较小 可以枚举xr和yr 若存在圆环 则该玩具可以被套中
*/
class Solution {
public:
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& ci, int r) {
        set<pair<int, int>> se;
        
        for (auto i : ci) {
            se.insert({i[0], i[1]});
        }
        
        int ans = 0;
        
        int dir[4][2] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}}; //方向
        
        for (auto toy : toys) {
            int xt = toy[0], yt = toy[1], t = toy[2];
            
            if (t > r)
                continue;
            
            int sr = (t - r) * (t - r);
            
            bool f = false;
            for (int dx = 0; dx * dx <= sr && !f; dx ++ )
                for (int dy = 0; dx * dx + dy * dy <= sr && !f; dy ++ ) {
                    for (int i = 0; i < 4 && !f; i ++ ) {
                        int xr = xt + dx * dir[i][0], yr = yt + dy * dir[i][1];
                        if (se.count({xr, yr})) {
                            ans ++ ;
                            f = true;
                        }
                    }
                }
        }
        
        return ans;
    }
};