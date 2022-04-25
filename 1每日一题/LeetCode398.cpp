class Solution {
public:
    vector<int> a;

    Solution(vector<int>& nums) {
        a = nums;
    }
    
    int pick(int target) {
        int c = 0, n = 1;
        for (int i = 0; i < a.size(); i ++ ) {
            if (a[i] == target) {
                if (rand() % n == 0)
                    c = i;
                n ++ ;
            }
        }
        return c;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
