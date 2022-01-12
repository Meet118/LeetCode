class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int x : nums) {
            if (x > b)
                return true;
            if (x <= a) {
                a = x;
            }
            else if (x <= b)
                b = x;
        }
        return false;
    }
};
