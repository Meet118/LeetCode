class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        int ac = 0, bc = 0;

        for (int x : nums) {
            if (x == a) {
                ac ++ ;
            }
            else if (x == b) {
                bc ++ ;
            }
            else if (ac == 0) {
                ac ++ ;
                a = x;
            }
            else if (bc == 0) {
                bc ++ ;
                b = x; 
            }
            else {
                ac -- ;
                bc -- ;
            }
        }
        vector<int> ans;
        ac = 0, bc = 0;
        for (int x : nums) {
            if (x == a)
                ac ++ ;
            if (x == b)
                bc ++ ;
        }
        if (ac > nums.size() / 3)
            ans.push_back(a);
        if (bc > nums.size() / 3)
            ans.push_back(b);
        return ans;
    }
};