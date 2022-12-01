class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans, m = 1e9;
        int i = 0;
        for (auto &p : points) {
            if (p[0] == x) {
                if (abs(p[1] - y) < m) {
                    m = abs(p[1] - y);
                    ans = i;
                }
            }
            if (p[1] == y) {
                if (abs(p[0] - x) < m) {
                    m = abs(p[0] - x);
                    ans = i;
                }
            }
            i ++ ;
        }
        return m == 1e9 ? -1 : ans;
    }
};
