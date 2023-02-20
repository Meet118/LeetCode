class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n) {
            if (n & 1) {
                if ((n >> 1) & 1)
                    n ++ ;
                ans ++ ;
            }
            n >>= 1;
        }
        return ans;
    }
};

