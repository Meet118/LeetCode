//单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int n = nums2.size();
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i -- ) {
            while (stk.size() && stk.top() < nums2[i])
                stk.pop();
            if (stk.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i ++ )
            ans.push_back(mp[nums1[i]]);
        return ans;
    }
};