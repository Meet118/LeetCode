//贪心 取最优方案
class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i ++ ) {
            if (s[i] == 'X') {
                ans ++ ;
                s[i] == 'O';
                if (i + 1 < n)
                    s[i + 1] = 'O';
                if (i + 2 < n)
                    s[i + 2] = 'O';
            }
        }
        return ans;
    }
};