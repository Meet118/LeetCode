class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> a(3);
        for (int x : stones)
            a[x % 3] ++ ;
        int l = max(a[1], a[2]), r = min(a[1], a[2]);
        if (a[0] % 2 == 0)
            return r > 0;
        else
            return l - r > 2;
    }
};
