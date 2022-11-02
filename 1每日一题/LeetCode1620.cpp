class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int cx = 0, cy = 0;
        int m = 0;
        for (int x = 0; x <= 50; x ++ )
            for (int y = 0; y <= 50; y ++ ) {
                int s = 0;
                for (auto& e : towers) {
                    if ((e[0] - x) * (e[0] - x) + (e[1] - y) * (e[1] - y) <= radius * radius) {
                        s += (int)((double)e[2] / (1 + sqrt((e[0] - x) * (e[0] - x) + (e[1] - y) * (e[1] - y))));
                    }
                }
                if (s > m) {
                    m = s;
                    cx = x, cy = y;
                }
            }
        return {cx, cy};
    }
};
