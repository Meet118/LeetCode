//双指针
class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0, j; i < n;) {
            j = i;
            while (j < n && s[j] != ' ') j ++ ;
            if (j != i)
                cnt ++ ;
            i = j + 1;
        }
        return cnt;
    }
};