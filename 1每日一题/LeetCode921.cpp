class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = 0;
        int cnt = 0;
        for (char c : s) {
            if (c == '(') n ++ ;
            else n -- ;
            if (n < 0) {
                cnt ++ ;
                n ++ ;
            }
        }
        return cnt + n;
    }
};
