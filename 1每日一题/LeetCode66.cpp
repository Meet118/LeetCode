class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int t = 0; //表示进位
        while (n >= 0) {
            if (digits[n] + 1 == 10) {
                digits[n] = 0;
                t = 1;
                n -- ;
            }
            else {
                t = 0;
                digits[n] ++ ;
                break;
            }
        }
        if (t)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};