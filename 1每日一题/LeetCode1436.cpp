class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;

        for (auto i : paths) {
            mp[i[0]] += 1;
            mp[i[1]] += 2;
        }

        for (auto& [k, v] : mp) {
            if (v == 2)
                return k;
        }

        return "";
    }
};