class Solution {
public:
    int magicalString(int n) {
        int num = 2;
        string s = "1";
        for (int i = 1; i < n; i ++ ) {
            int cnt = i < s.size() ? s[i] - '0' : 2;
            s += string(cnt, '0' + num);
            num = 3 - num;
            if (s.size() >= n) break;
        }
        int ans = 0;
        for (int i = 0; i < n; i ++ )
            if (s[i] == '1')
                ans ++ ;
        return ans;
    }
};
