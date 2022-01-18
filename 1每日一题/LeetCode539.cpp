class Solution {
public:
    int get(int h, int m) {
        return h * 60 + m;
    }

    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 24 * 60)
            return 0;
        vector<pair<int, int>> a;
        for (string s : timePoints) {
            string x = s.substr(0, 2);
            string y = s.substr(3, 2);
            a.push_back({stoi(x), stoi(y)});
        }
        sort(a.begin(), a.end());
        int ans = 1e9;
        for (int i = 0; i + 1 < a.size(); i ++ ) {
            int t = get(a[i + 1].first, a[i + 1].second) - get(a[i].first, a[i].second);
            ans = min(ans, t);
        }

        return min(ans, get(a[0].first, a[0].second) - get(a.back().first, a.back().second) + 60 * 24);
    }
};
