class Solution {
public:
    typedef long long ll;

    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid, n, index, maxSum)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    bool check(ll x, int n, int index, int maxSum) {
        ll res = 0;
        if (x > index) res += (x + x - index) * (index + 1) / 2;
        else res += (1 + x) * x / 2 + index - x + 1;
        x -- ;
        index = n - index - 2;
        if (x > index) res += (x + x - index) * (index + 1) / 2;
        else res += (1 + x) * x / 2 + index - x + 1;
        return res >= 0 && res <= (ll)maxSum;
    }
};
