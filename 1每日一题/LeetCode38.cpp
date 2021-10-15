class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        n -- ;
        while (n -- ) {
            string t = "";
            int m = ans.size();
            for (int i = 0, j; i < m;) {
                j = i;
                while (j < m && ans[j] == ans[i]) j ++ ;
                t += to_string(j - i);
                t += ans[i];
                i = j;
            }
            ans = t;
        }
        return ans;
    }
};