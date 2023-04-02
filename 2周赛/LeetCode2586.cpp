class Solution {
public:
    bool check(char c ) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i ++ ) {
            if (check(words[i].back()) && check(words[i][0]))
                ans ++ ;
        }
        return ans;
    }
};

