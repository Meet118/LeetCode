class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0, j; i < n;) {
            j = i + 1;
            while (j < n && s[j] == s[i]) j ++ ;
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};
