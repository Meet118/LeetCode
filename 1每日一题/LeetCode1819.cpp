class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = 200010;
        vector<int> st(n + 1);
        int m = 0;
        for (int x : nums)
            st[x] = 1, m = max(m, x);
        int ans = 0;
        for (int i = 1; i <= m; i ++ ) {
            int g = 0;
            for (int j = i; j <= m && g != i; j += i) {
                if (st[j])
                    g = gcd(g, j);
            }
            if (g == i)
                ans ++ ;
        }
        return ans;
    }

    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
};
