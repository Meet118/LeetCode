class Solution {
public:
    struct Node {
        int st, ed, pr;
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Node> a;
        int n = startTime.size();
        for (int i = 0; i < n; i ++ ) a.push_back({startTime[i], endTime[i], profit[i]});
        sort(a.begin(), a.end(), [&](const Node x, const Node y) {
            return x.ed < y.ed;
        });
        vector<int> f(n);
        f[0] = a[0].pr;
        for (int i = 1; i < n; i ++ ) {
            f[i] = max(f[i - 1], a[i].pr);
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (a[mid].ed <= a[i].st) l = mid;
                else r = mid - 1;
            }
            if (a[l].ed <= a[i].st)
                f[i] = max(f[i], f[l] + a[i].pr);
        }
        return f[n - 1];
    }
};
