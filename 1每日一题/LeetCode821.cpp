class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> a;
        int n = s.size();
        for (int i = 0; i < n; i ++ )
            if (s[i] == c)
                a.push_back(i);
        vector<int> ans(n, 1e9);
        for (int i = 0; i < n; i ++ ) {
            int pos = lower_bound(a.begin(), a.end(), i) - a.begin();
            if (pos < a.size())
                ans[i] = a[pos] - i;
            if (pos - 1 >= 0 && pos - 1 < a.size())
                ans[i] = min(ans[i], i - a[pos - 1]);
        }
        return ans;
    }
};
