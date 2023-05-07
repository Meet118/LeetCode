class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i ++ ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j ++ ;
                int m = j;
                while (j < n && s[j] == '1') j ++ ;
                if (j - m >= m - i) //1的长度大于等于0的长度
                    ans = max(ans, (m - i) * 2);
            }
        }
        return ans;
    }
};

