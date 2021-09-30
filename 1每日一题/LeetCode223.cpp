class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int c = 0;
        int yl = max(ax1, bx1);
        int yr = min(ax2, bx2);
        int xd = max(ay1, by1);
        int xu = min(ay2, by2);
        if (yl < yr && xu > xd)
            c = (yr - yl) * (xu - xd);
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - c;
    }
};