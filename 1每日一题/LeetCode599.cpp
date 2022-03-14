class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); i ++ )
            mp[list1[i]] = i;
        int sum = 1e9;
        for (int j = 0; j < list2.size(); j ++ ) {
            if (mp.count(list2[j])) {
                if (mp[list2[j]] + j < sum) {
                    ans.clear();
                    ans.push_back(list2[j]);
                    sum = mp[list2[j]] + j;
                }
                else if (mp[list2[j]] + j == sum)
                    ans.push_back(list2[j]);
            }
        }
        return ans;
    }
};
