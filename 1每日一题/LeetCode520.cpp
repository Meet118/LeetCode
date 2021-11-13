class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt = 0;
        for (int i = 1; i < n; i ++ ) {
            if (word[i] >= 'A' && word[i] <= 'Z')
                cnt ++ ;
        }
        return cnt == 0 || word[0] >= 'A' && word[0] <= 'Z' && cnt == n - 1;
    }
};