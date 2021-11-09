class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1, r = 1e5;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, q, n)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    bool check(int x, vector<int>& q, int n) {
        int s = 0;
        for (int i : q) {
            s += (i - 1) / x + 1;
        }
        return s <= n;
    }
};
