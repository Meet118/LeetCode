class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for (int i = 1, j = 0; i <= n && j < target.size(); i ++ ) {
            if (i < target[j]) {
                ans.push_back("Push");
                ans.push_back("Pop");
            } else if (i == target[j]) {
                ans.push_back("Push");
                j ++ ;
            }
        }
        return ans;
    }
};
