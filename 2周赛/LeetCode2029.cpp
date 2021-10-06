//分情况讨论
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> a(3);
        for (int x : stones)
            a[x % 3] ++ ;
        int small = min(a[1], a[2]), large = max(a[1], a[2]);
        if (a[0] % 2 == 0) {
            if (small > 0)
                return true;
            return false;
        }
        else {
            if (large - small > 2)
                return true;
            return false;
        }
    }
};