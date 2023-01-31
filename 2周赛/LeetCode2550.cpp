class Solution {
public:
    typedef long long ll;

    ll qmi(ll a, ll b, ll mod) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    int monkeyMove(int n) {
        ll mod = 1e9 + 7;
        return (qmi(2, n, mod) + mod - 2) % mod;
    }
};

