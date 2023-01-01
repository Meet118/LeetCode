class Solution {
public:
    char repeatedCharacter(string s) {
        int state = 0;
        for (auto ch : s) {
            int t = ch - 'a';
            if (state >> t & 1)
                return ch;
            state |= (1 << t);
        }
        return 'a';
    }
};
