class Solution {
public:
    int countValidWords(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            while (i < n && s[i] == ' ') i ++ ;
            if (i == n)
                break;
            int j = i;
            
            while (j < n && s[j] != ' ') j ++ ;
            
            string t = s.substr(i, j - i);
            bool f = true;
            int cnt = 0;
            for (char c : t) {
                if (isdigit(c))
                    f = false;
                if (c == '-')
                    cnt ++ ;
            }
            if (cnt > 1)
                f = false;
            for (int k = 0; k < t.size() - 1; k ++ )
                if (t[k] == '.' || t[k] == '!' || t[k] == ',')
                    f = false;
            if (t.back() == '-' || t[0] == '-')
                f = false;
            int k = t.size() - 1;
            if (t[k] == '.' || t[k] == '!' || t[k] == ',') {
                t.pop_back();
                if (t.back() == '-')
                    f = false;
            }
            
            if (f)
                ans ++ ;
            i = j;
        }
        return ans;
    }
};
