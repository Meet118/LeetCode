class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> c(101);
        for (int x : nums1) c[x] |= 1;
        for (int x : nums2) c[x] |= (1 << 2);
        for (int x : nums3) c[x] |= (1 << 3);
        vector<int> ans;
        for (int i = 1; i <= 100; i ++ )
            if (get(c[i]) > 1) ans.push_back(i);
        return ans;
    }

    int get(int x) {
        int res = 0;
        while (x) {
            x -= x & (-x);
            res ++ ;
        }
        return res;
    }
};
