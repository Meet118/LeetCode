//单调栈
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        int all_letter = 0;
        for (char c : s)
            if (c == letter)
                all_letter ++ ;
        string ans;
        int cur = 0;
        for (int i = 0; i < n; i ++ ) {
            while (ans.size() && ans.back() > s[i] && (ans.size() - 1 + n - i >= k)) {
                if (ans.back() == letter && all_letter + cur - 1 < repetition)
                    break;
                if (ans.back() == letter)
                    cur -- ;
                ans.pop_back();
            }
            if (s[i] == letter)
                all_letter -- ;
            if (ans.size() < k) {
                if (s[i] == letter || (k - ans.size()) > max(0, repetition - cur)) {
                    ans.push_back(s[i]);
                    cur += s[i] == letter;
                }
            }
        }
        return ans;
    }
};