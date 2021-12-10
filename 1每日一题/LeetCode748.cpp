class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> cnt;
        for (auto c : licensePlate)
            if (isalpha(c)) {
                c = tolower(c);
                cnt[c] ++ ;
            }
        int min_len = 1e9;
        string ans;
        for (string s : words) {
            bool f = true;
            unordered_map<char, int> t;
            t = cnt;
            for (char c : s) {
                if (isalpha(c)) {
                    c = tolower(c);
                    t[c] -- ;
                }
            }
            for (auto& [k, v] : t)
                if (v > 0) {
                    f = false;
                    break;
                }
            if (f && s.size() < min_len)
                ans = s, min_len = s.size();
        }
        return ans;
    }
};
