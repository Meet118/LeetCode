class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for (auto s : cpdomains) {
            int n = s.size();
            int idx = 0;
            while (idx < s.size() && isdigit(s[idx])) idx ++ ;
            int num = stoi(s.substr(0, idx));
            for (int i = idx; i < s.size(); i ++ ) {
                if (i == idx || s[i] == '.') {
                    string cur = s.substr(i + 1, n - i);
                    mp[cur] += num;
                }
            }
        }
        vector<string> ans;
        for (auto &[k, v] : mp) {
            ans.push_back(to_string(mp[k]) + ' ' + k);
        }
        return ans;
    }
};
