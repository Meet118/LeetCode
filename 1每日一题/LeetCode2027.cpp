class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ) {
            if (s[i] == 'X') {
                ans ++ ;
                i += 3;
            }
            else {
                i ++ ;
            }
        }
        return ans;
    }
};
