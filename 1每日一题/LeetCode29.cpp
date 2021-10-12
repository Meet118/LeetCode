class Solution {
public:
    int divide(int x, int y) {
        if (x == INT_MIN && y == -1)
            return INT_MAX;
        bool f = false;
        if (x > 0 && y < 0 || x < 0 && y > 0)
            f = true;
        if (x > 0) x = -x;
        if (y > 0) y = -y;
        vector<int> a;
        a.push_back(y);
        while (y >= INT_MIN - y) {
            y += y;
            a.push_back(y);
        }
        int n = a.size();
        int ans = 0;
        while (n -- ) {
            ans += ans;
            if (x <= a[n]) {
                x -= a[n];
                ans -= 1;
            }
        }
        if (!f)
            ans = -ans;
        return ans;
    }
};