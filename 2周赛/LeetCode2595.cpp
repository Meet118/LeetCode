class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        int f = 0;
        while (n) {
            if (n & 1) {
                ans[f] ++ ;                    
            }
            f ^= 1;
            n >>= 1;
        }
        return ans;
    }
};

