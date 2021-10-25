class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1;; i ++ ) {
            if (check(i))
                return i;
        }
        return 0;
    }
    
    bool check(int x) {
        string s = to_string(x);
        vector<int> a(10, 0);
        for (auto c : s)
            a[c - '0'] ++ ;
        for (int i = 0; i < 10; i ++ ) {
            if (a[i] > 0 && a[i] != i)
                return false;
        }
        return true;
    }
};
