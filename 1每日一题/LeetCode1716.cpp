class Solution {
public:
    int totalMoney(int n) {
        int mon = 1, cur = 1, ans = 0;
        for (int i = 1; i <= n; i ++ ) {
            cur ++ ;
            if (i % 7 == 1) {
                cur = mon ++ ;
            }
            ans += cur;
        }
        return ans;
    }
};
