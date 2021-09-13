class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 0;
        for (int i = 0; i < n; i ++ ) { //用哈希表存储任意两点之间的距离 和当前点距离相同的两个点可构成一个回旋镖
            unordered_map<int, int> mp;

            for (int j = 0; j < n; j ++ ) {
                if (j == i)
                    continue;
                int dis = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                mp[dis] ++ ;
            }

            for (auto j : mp) {
                ans += j.second * (j.second - 1);
            }
        }

        return ans;
    }
};