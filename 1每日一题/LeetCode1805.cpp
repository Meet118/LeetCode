class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> se;
        for (int i = 0; i < word.size(); i ++ ) {
            if (!isdigit(word[i])) continue;
            int j = i;
            while (j < word.size() && isdigit(word[j])) {
                j ++ ;
            }
            string s = word.substr(i, j - i);
            int k = 0;
            while (k + 1 < s.size() && s[k] == '0') k ++ ;
            i = j - 1;
            se.insert(s.substr(k));
        }
        return se.size();
    }
};
