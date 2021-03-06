class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> se(banned.begin(), banned.end());
        unordered_map<string, int> cnt;
        string word;
        for (auto c: paragraph) {
            c = tolower(c);
            if (c >= 'a' && c <= 'z') word += c;
            else {
                if (word.size()) {
                    if (!se.count(word)) cnt[word] ++ ;
                    word.clear();
                }
            }
        }
        if (word.size() && !se.count(word))
            cnt[word] ++ ;
        string res;
        for (auto& [k, v]: cnt)
            if (cnt[res] < v)
                res = k;
        return res;
    }
};

