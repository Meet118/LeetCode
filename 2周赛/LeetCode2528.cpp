typedef long long ll;

class Solution {
public:
    int n;
    
    long long maxPower(vector<int>& num, int m, int k) {
        n = num.size();
        vector<ll> s(n + 1); //前缀和数组
        vector<ll> a(n); //初始状态的电量
        for (int i = 0; i < n; i ++ ) s[i + 1] = s[i] + num[i];
        for (int i = 0; i < n; i ++ ) {
            int l = max(1, i - m + 1), r = min(i + m + 1, n);
            a[i] = s[r] - s[l - 1];
        }
        vector<ll> b(n + 2); //差分数组
        for (int i = 0; i < n; i ++ ) {
            if (i) b[i + 1] = a[i] - a[i - 1];
            else b[i + 1] = a[i];
        }
        ll l = 0, r = 1e18;
        while (l < r) {
            ll mid = l + r + 1 >> 1;
            if (check(mid, b, k, m)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
    
    bool check(ll x, vector<ll> b, ll k, int m) { //x为每座城市要达到的电量，b是差分数组，k是可建造的数量，m是半径
        for (int i = 1; i <= n; i ++ ) {
            b[i] += b[i - 1]; //每次累加得出当前电量
            ll cur = b[i]; //第i座城市的电量
            if (cur < x) {
                ll t = x - cur;
                if (k < t) return false; //可建造的数量不足
                k -= t;
                int l = i, r = min(n, i + m * 2);
                b[r + 1] -= t;
                b[l] += t;
            }
        }
        return true;
    }
};

