//试除法
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n % 3 == 0 && n != 0)
            n /= 3;
        return n == 1;
    }
};
//判断最大幂的约数 1162261467 = pow(3, 19) 如果n是给定范围内的最大3的幂的约数 则也是3的幂
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};