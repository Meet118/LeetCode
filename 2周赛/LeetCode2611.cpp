class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        int ans = 0;
        vector<pair<int, int>> a;
        int n = r1.size();
        for (int i = 0; i < n; i ++ ) {
            a.push_back({r1[i] - r2[i], i});
        }
        sort(a.begin(), a.end(), greater<>());
        for (int i = 0; i < n; i ++ ) {
            if (i < k) ans += r1[a[i].second];
            else ans += r2[a[i].second];
        }
        return ans;
    }
};

