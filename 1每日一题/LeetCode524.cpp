class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int n = s.size();
        for (auto dic : dictionary) {
            int i = 0, j = 0;
            
            while (i < n && j < dic.size()) { //双指针 判断一个字符串是否是另一个字符串的子序列
                if (s[i] == dic[j]) {
                    j ++ ;
                }
                i ++ ;
            }
            if (j == dic.size()) {
                if (j > ans.size())
                    ans = dic;
                else if (j == ans.size() && dic < ans)
                    ans = dic;
            }
        }
        return ans;
    }
};