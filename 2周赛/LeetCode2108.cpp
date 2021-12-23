class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            int i = 0, j = s.size() - 1;
            bool f = true;
            while (i < j) {
                if (s[i] != s[j]) {
                    f = false;
                    break;
                }
                i ++ , j -- ;
            }
            if (f)
                return s;
        }
        return "";
    }
};

