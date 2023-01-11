class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(10);
        for (char c : num) cnt[c - '0'] ++ ;
        for (int i = 0; i < num.size(); i ++ )
            if (num[i] - '0' != cnt[i])
                return false;
        return true;
    }
};
