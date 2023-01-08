class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string word : words) {
            int j = 0;
            for (int i = 0; i < pref.size(); i ++ ) {
                if (j < word.size() && pref[i] == word[j]) j ++ ;
                else break;
            }
            if (j == pref.size()) ans ++ ;
        }
        return ans;
    }
};
