class Solution {
public:
    bool winnerOfGame(string s) {
        int a = 0, b = 0;
        int n = s.size();
        for (int i = 0; i < s.size();) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j ++ ;
            if (j - i > 2) {
                if (s[i] == 'A')
                    a += j - i - 2;
                else
                    b += j - i - 2;
            }
            i = j;
        }
        return a > b;
    }
};
