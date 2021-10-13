class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        sort(nums3.begin(), nums3.end());
        nums3.erase(unique(nums3.begin(), nums3.end()), nums3.end());
        for (int i : nums1)
            mp[i] ++ ;
        for (int i : nums2)
            mp[i] ++ ;
        for (int i : nums3)
            mp[i] ++ ;
        
        vector<int> ans;
        for (auto i : mp)
            if (i.second > 1)
                ans.push_back(i.first);
        return ans;
    }
};