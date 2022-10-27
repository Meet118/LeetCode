class Solution {
public:
    int arraySign(vector<int>& nums) {
        int c = 0;
        for (int x : nums) {
            if (x < 0) c ++ ;
            else if (x == 0) return 0;
        }
        return c % 2 == 0 ? 1 : -1;
    }
};
