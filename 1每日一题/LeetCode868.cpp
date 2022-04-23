class Solution {
public:
    int binaryGap(int n) {
        int la = -1, cur = 0, ans = 0;
        while (n) {
            if (n & 1) {
                if (la != -1)
                    ans = max(ans, cur - la);
                la = cur;
            }                
            cur ++ ;
            n >>= 1;
        }
        return ans;
    }
};
