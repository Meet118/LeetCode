class Solution {
public:
    int mod = 1337;

    int qmi(int a, int b) {
        int res = 1;
        a %= mod;
        while (b) {
            if ((b & 1) == 1)
                res = res * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int x : b) {
            res = qmi(res, 10);
            res *= qmi(a, x);
        }
        return res % mod;
    }
};
