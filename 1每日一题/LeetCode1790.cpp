class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int cnt = 0;
        char a, b;
        for (int i = 0; i < n; i ++ ) {
            if (s1[i] != s2[i]) {
                if (cnt == 1) {
                    if (!(b == s1[i] && a == s2[i]))
                        return false;
                }
                else if (cnt == 0) {
                    a = s1[i], b = s2[i];
                }
                else {
                    return false;
                }
                cnt ++ ;
            }
        }
        return cnt == 0 || cnt == 2;
    }
};
