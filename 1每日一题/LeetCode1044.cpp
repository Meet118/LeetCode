typedef unsigned long long ull;
class Solution {
public:
    int P = 131;
    vector<ull> p, h;
    string ans = "";

    ull find(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        p.resize(n + 1);
        h.resize(n + 1);

        s = ' ' + s;
        p[0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i] - 'a' + 1;
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid, s)) l = mid;
            else r = mid - 1;
        }
        return ans;
    }

    bool check(int len, string& s) {
        unordered_set<ull> se;
        for (int i = 1; i + len - 1 < s.size(); i ++ ) {
            if (se.count(find(i, i + len - 1))) {
                ans = s.substr(i, len);
                return true;
            }
            se.insert(find(i, i + len - 1));
        }
        return false;
    }
};
