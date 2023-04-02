class Solution {
public:
    bool primeSubOperation(vector<int>& a) {
        int m = 1010;
        // 筛质数
        vector<int> p;
        vector<int> st(m + 1);
        for (int i = 2; i < m; i ++ ) {
            if (!st[i]) p.push_back(i);
            for (int j = 0; p[j] * i <= m; j ++ ) {
                st[p[j] * i] = 1;
                if (i % p[j] == 0) break;
            }
        }
        p.insert(p.begin(), 0); //减去0也可以
        int n = a.size();
        int la = 0; //上个数
        for (int i = 0; i < n; i ++ ) {
            int l = 0, r = p.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (p[mid] + la < a[i]) l = mid;
                else r = mid - 1;
            }
            if (p[l] + la < a[i]) {
                a[i] -= p[l];
                la = a[i];
            }
            else return false;
        }
        return true;
    }
};

