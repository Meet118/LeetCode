class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> f(10);
        f[0] = 1;
        f[1] = 10;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = f[i - 1];
            int t = 9;
            for (int j = 9; j > 9 - i + 1; j -- )
                t *= j;
            f[i] += t;
        }
        return f[n];
    }
};
