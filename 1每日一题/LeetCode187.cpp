class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> se, tmp;
        int n = s.size();
        vector<string> ans;
        for (int i = 0; i + 10 <= n; i ++ ) {
            string t = s.substr(i, 10);
            if (se.count(t))
                tmp.insert(t);
            else
                se.insert(t);
        }
        for (auto i : tmp)
            ans.push_back(i);
        return ans;
    }
};