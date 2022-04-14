class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > 0 && ty > 0) {
            if (tx == sx && ty == sy)
                return true;
            if (tx > ty)
                tx -= max((tx - sx) / ty, 1) * ty;
            else
                ty -= max((ty - sy) / tx, 1) * tx;
        }
        return false;
    }
};
