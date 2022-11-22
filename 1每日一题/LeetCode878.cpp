typedef long long ll;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll l = 0, r = 1e18;
        const int mod = 1e9 + 7;
        while (l < r) {
            ll mid = l + r >> 1;
            if (check(mid, a, b) >= n) r = mid;
            else l = mid + 1;
        }
        return l % mod;
    }

    ll check(ll x, int a, int b) {
        return x / a + x / b - x / (a * b / gcd(a, b));
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
