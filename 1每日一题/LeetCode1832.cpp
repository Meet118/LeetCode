class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> cnt(26);
        for (auto c : sentence) {
            cnt[c - 'a'] ++ ;
        }
        for (int x : cnt)
            if (x == 0) return false;
        return true;
    }
};
