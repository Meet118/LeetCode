class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            int t = x;
            a += t;
            while (t) {
                b += t % 10;
                t /= 10;
            }
        }
        return abs(a - b);
    }
};

