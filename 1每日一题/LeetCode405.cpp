class Solution {
public:
    string toHex(int num) {
        unsigned x = num; //转成无符号整数
        if (x == 0)
            return "0";
        string ans = "";
        while (x) {
            int n = x & 0xf; //每次取四位
            if (n >= 10)
                ans += 'a' + n - 10;
            else
                ans += '0' + n;
            x >>= 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};