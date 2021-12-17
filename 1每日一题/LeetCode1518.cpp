class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int blank = 0;
        while (true) {
            ans += numBottles;
            blank += numBottles;
            numBottles = blank / numExchange;
            blank -= numBottles * numExchange;
            if (numBottles == 0)
                break;
        }
        return ans;
    }
};
