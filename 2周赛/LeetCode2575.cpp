class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long d = 0;
        for (int i = 0; i < word.size(); i ++ ) {
            d = d * 10 + word[i] - '0';
            d %= m;
            ans.push_back(!d);
        }
        return ans;
    }
};
