class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        int n = a.size();
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, a, p)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    bool check(int x, vector<int>& a, int p) {
        int t = p;
        for (int i = 0; i + 1 < a.size();) {
            if (a[i + 1] - a[i] <= x) {
                p -- ;
                i += 2;                
            } else i ++ ;
        }
        return p <= 0;
    }
};

