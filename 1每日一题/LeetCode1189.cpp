class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        string s = "balon";
        for (char c : text) {
            if (s.find(c) != s.npos)
                mp[c] ++ ;
        }
        int ans = 1e9;
        for (int i = 0; i < s.size(); i ++ ) {
            char c = s[i];
            if (c == 'l' || c == 'o')
                ans = min(ans, mp[c] / 2);
            else
                ans = min(ans, mp[c]);
        }
        return ans;
    }
};
