class Solution {
public:
    int getSum(int a, int b) {
        unsigned num = 0, carry = 1;
        while (carry) {
            num = a ^ b; //计算不进位的加法
            carry = a & b; //计算进位
            a = num, b = carry << 1;
        }
        return num;
    }
};