class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0, k = 0;
        for (char c : s) {
            if (k < spaces.size() && i == spaces[k])
                ans.push_back(' '), k ++ ;
            ans.push_back(c);
            i ++ ;
        }
        return ans;
    }
};

