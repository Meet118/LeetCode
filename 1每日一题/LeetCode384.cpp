class Solution {
public:
    vector<int> a;

    Solution(vector<int>& nums) {
        a = nums;
    }
    
    vector<int> reset() {
        return a;
    }
    
    vector<int> shuffle() {
        vector<int> b;
        b = a;
        int n = a.size();
        for (int i = 0; i < n; i ++ ) {
            int t = rand() % (n - i) + i;
            swap(b[i], b[t]);
        }
        return b;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
