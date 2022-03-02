typedef long long ll;
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        set<ll> se;
        se.insert(pow(10, len) + 1);
        se.insert(pow(10, len - 1) - 1);
        ll m = stoll(n.substr(0, (len + 1) / 2));
        for (ll i = m - 1; i <= m + 1; i ++ ) {
            string a = to_string(i), b = a;
            reverse(b.begin(), b.end());
            if (len % 2) se.insert(stoll(a + b.substr(1)));
            else se.insert(stoll(a + b));
        }
        se.erase(stoll(n));
        string ans = "";
        ll k = 1e18;
        for (auto i : se) {
            if (abs(i - stoll(n)) < k) {
                ans = to_string(i);
                k = abs(i - stoll(n));
            }
            else if (abs(i - stoll(n)) == k && i < stoll(ans))
                ans = to_string(i);
        }
        return ans;
    }
};
