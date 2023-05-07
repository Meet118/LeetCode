class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int i = n - 1; //从最右边开始考虑
        s[i] ++ ;
        while (i < n && i >= 0) {
            if (s[i] == 'a' + k) { //超出最高位
                if (i == 0) return ""; //此时已经是最左
                s[i] = 'a';
                s[ -- i] ++ ; //上一位进位
            } else if (i > 0 && s[i] == s[i - 1] || i > 1 && s[i] == s[i - 2]) { ///不满足回文
                s[i] ++ ;
            } else {
                i ++ ; //检查右边是否满足
            }
        }
        return s;
    }
};

