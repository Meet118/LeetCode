//模拟
class Solution {
public:
    int arrangeCoins(int n) {
        long long a = 0;
        for (int i = 1; ; i ++ ) {
            a += i;
            if (a > n)
                return i - 1;
        }
        return 0;
    }
};

//数学
class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(8.0 * n + 1)) / 2;
    }
};