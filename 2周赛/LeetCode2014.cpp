/*
统计出d中出现次数大于等于k的字符 答案只能由这些字符组成 而这些字符的个数不会超过n/k 而n<8*k 故字符数量最多为7
暴力枚举目标字符的所有可能组成的字符串 再检查是否满足要求 长度最长且字典序最大的字符串即为所求
*/
class Solution {
public:
    bool check(string s, string t, int k) { //检查k个t是否是s的子串
        string sc = "";
        while (k -- )
            sc += t;
        int j = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (j < sc.size() && s[i] == sc[j])
                j ++ ;
        }
        return j == sc.size();
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> cnt(26); //记录各个字符出现的次数

        for (auto c : s)
            cnt[c - 'a'] ++ ;

        vector<char> fc; //记录出现大于等于k次的字符
        for (int i = 0; i < 26; i ++ )
            if (cnt[i] >= k)
                fc.push_back('a' + i);
        
        vector<string> fs[8]; //从小到大枚举所有由出现大于k次的字符组成的字符串 fs[i]表示长度为i
        fs[0].push_back("");
        int len;
        for (len = 1; len < 8; len ++ ) { //枚举长度 每个更长的字符串都是由长度减1的满足要求的字符串转化而来
            for (string la : fs[len - 1]) {
                for (char c : fc) {
                    if (check(s, la + c, k))
                        fs[len].push_back(la + c);
                }
            }
            if (fs[len].size() == 0)
                break;
        }
        sort(fs[len - 1].begin(), fs[len - 1].end()); //排序取字典序最大
        return fs[len - 1].back();
    }
};