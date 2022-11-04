class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int n = 0;
        while (sum < target || (sum - target) % 2) {
            n ++ ;
            sum += n;
        }
        return n;
    }
};
