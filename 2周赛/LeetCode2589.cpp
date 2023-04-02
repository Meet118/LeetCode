class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int m = 0;
        for (auto x : tasks)
            m = max(m, x[1]);
        int ans = 0;
        for (int i = 1; i <= m; i ++ ) {
            bool f = false; //判断当前时间点是否必选
            for (auto& x : tasks) {
                if (i >= x[0] && i <= x[1] && (x[1] - i < x[2])) { //剩余点不能满足时必选
                    f = true;
                    break;
                }
            }
            if (f) { //要选当前时间点
                ans ++ ;
                for (auto& x : tasks) {
                    if (i >= x[0] && i <= x[1] && x[2] > 0) //减去包含当前点的
                        x[2] -- ;
                }
            }
        }
        return ans;
    }
};

