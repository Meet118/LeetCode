class Solution {
public:
    bool hasAlternatingBits(int n) {
        int la = 0;
        int i = 0;
        while (n) {
            int cur = (n & 1);
            if (i && cur == la)
                return false;
            la = cur;
            i ++ ;
            n >>= 1;
        }
        return true;
    }
};
