class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; i ++ ) {
            int x = i;
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            mp[sum] ++ ;
            ans = max(ans, mp[sum]);
        }
        return ans;
    }
};
