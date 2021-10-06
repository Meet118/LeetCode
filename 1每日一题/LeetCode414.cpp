class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long INF = 1e18, a = -INF, b = -INF, c = -INF;
        for (int x : nums) {
            if (x == a || x == b || x == c)
                continue;
            if (x > a)
                c = b, b = a, a = x;
            else if (x > b)
                c = b, b = x;
            else if (x > c)
                c = x;
        }
        if (c == -INF)
            return a;
        return c;
    }
};