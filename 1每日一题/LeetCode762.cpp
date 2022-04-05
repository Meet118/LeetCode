class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> se {2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int num = left; num <= right; num ++ ) {
            int x = num;
            int cnt = 0;
            while (x) {
                cnt ++ ;
                x -= (x & -x);
            }
            if (se.count(cnt))
                ans ++ ;
        }
        return ans;
    }
};
