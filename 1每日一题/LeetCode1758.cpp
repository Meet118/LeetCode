class Solution {
public:
    int minOperations(string s) {
        int a = 0, n = s.size();
        for (int i = 0; i < n; i ++ ) {
            if (s[i] != '0' + i % 2) a ++ ;
        }
        return min(a, n - a);
    }
};
