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
            
            //t是找出的子串
            string t = s.substr(i, j - i);
            bool f = true;
            int cnt = 0;
            for (char c : t) { //遍历一遍查找是否含有数字和记录-出现的次数
                if (isdigit(c))
                    f = false;
                if (c == '-')
                    cnt ++ ;
            }
            if (cnt > 1) //-出现大于1次不符合
                f = false;
            for (int k = 0; k < t.size() - 1; k ++ ) //标点不能出现的除了最后一位以外的位置
                if (t[k] == '.' || t[k] == '!' || t[k] == ',')
                    f = false;
            if (t.back() == '-' || t[0] == '-') //-不能出现在开始或结束
                f = false;
            int k = t.size() - 1;
            if (t[k] == '.' || t[k] == '!' || t[k] == ',') { //最后一位是标点 倒数第二位不能是-（这个极易忽略）
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
