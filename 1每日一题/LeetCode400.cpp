class Solution {
public:
    int findNthDigit(int n) {
        int w = 1; //数的位数
        long long sw = 0, t = 9; //sw是总位数
        while (true) {
            sw += w * t;
            if (sw >= n)
                break;
            w ++ , t *= 10;
        }
        sw -= w * t;
        long long num = pow(10, w - 1) + (n - sw - 1) / w; //当前数
        long long di = pow(10, w - 1 - (n - sw - 1) % w);
        return num / di % 10;
    }
};
