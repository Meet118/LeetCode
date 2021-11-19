#define x first
#define y second
typedef pair<int, int> PII;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<PII, int> mp;
        int a = rectangles[0][0], b = rectangles[0][1], c = rectangles[0][2], d = rectangles[0][3];
        for (auto i : rectangles) {
            a = min(a, i[0]);
            b = min(b, i[1]);
            c = max(c, i[2]);
            d = max(d, i[3]);
            mp[{i[0], i[1]}] ++ ;
            mp[{i[2], i[1]}] ++ ;
            mp[{i[0], i[3]}] ++ ;
            mp[{i[2], i[3]}] ++ ;
        }
        bool f = false;
        for (auto& [k, v] : mp) {
            if (v == 1) {
                f = true;
                int x = k.x, y = k.y;
                if (!(x == a && y == b) && !(x == a && y == d) && !(x == c && y == b) && !(x == c && y == d))
                    return false;
            }
            else if (v != 2 && v != 4)
                 return false;
        }
        long long sum = (long long)(c - a) * (d - b);
        for (auto i : rectangles)
            sum -= (long long)(i[2] - i[0]) * (i[3] - i[1]);
        return sum == 0 && f;
    }
};
