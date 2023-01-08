class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int a = 0;
        for (int i : nums) a ^= i; 
        return a;
    }
};

