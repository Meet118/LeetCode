class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size() && cnt <= 1; i ++ ) {
            while (i < s.size() && s[i] == '0') i ++ ;
            if (i < s.size() && s[i] == '1') {
                int j = i;
                while (j < s.size() && s[j] == '1') j ++ ;
                cnt ++ ;
                i = j;
            }
        }
        return cnt <= 1;
    }
};
