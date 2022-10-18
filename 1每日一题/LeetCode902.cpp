class Solution {
public:
    int power(int a, int b) {
        int res = 1;
        while (b -- ) res *= a;
        return res;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int m) {
        string num = to_string(m);
        int ans = 0;
        int n = digits.size();
        for (int i = 1; i < num.size(); i ++ ) ans += power(n, i); //计算小于n位的
        bool flag = true;
        for (int i = 0; i < num.size(); i ++ ) { //计算等于n位的
            int x = num[i] - '0';
            int t = power(n, num.size() - i - 1);
            int j;
            for (j = 0; j < n; j ++ ) {
                int cur = digits[j][0] - '0';
                if (cur < x)
                    ans += t;
                else break;
            }
            if (!(j < n && digits[j][0] - '0' == x)) {
                flag = false;
                break;
            }
        }
        if (flag) ans ++ ;
        return ans;
    }
};
