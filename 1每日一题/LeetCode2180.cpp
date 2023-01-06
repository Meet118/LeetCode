class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; i ++ ) {
            int s = 0, x = i;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            if (s % 2 == 0) ans ++ ;
        }
        return ans;
    }
};
