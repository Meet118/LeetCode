class Solution {
public:
    int kthGrammar(int n, int k) {
        int ans = 0;
        k -- ;
        while (k) {
            if (k & 1) ans ^= 1;
            k >>= 1;
        }
        return ans;
    }
};
