class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        for (int i = 0, j; i < s1.size();) {
            j = i + 1;
            while (j < s1.size() && s1[j] != ' ') j ++ ;
            mp[s1.substr(i, j - i)] ++ ;
            i = j + 1;
        }
        for (int i = 0, j; i < s2.size();) {
            j = i + 1;
            while (j < s2.size() && s2[j] != ' ') j ++ ;
            mp[s2.substr(i, j - i)] ++ ;
            i = j + 1;
        }
        vector<string> ans;
        for (auto& [k, v] : mp) {
            if (v == 1)
                ans.push_back(k);
        }
        return ans;
    }
};
