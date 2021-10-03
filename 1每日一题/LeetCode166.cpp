class Solution {
public:
    string fractionToDecimal(int aa, int bb) {
        string ans = "";
        long long a = aa, b = bb;
        if (a * b < 0)
            ans += '-';
        a = abs(a), b = abs(b);
        ans += to_string(a / b);
        if (a % b != 0)
            ans += '.';
        int beg = ans.size();
        unordered_map<int, int> mp; //记录余数上次出现的位置
        int p = -1, c = 0;
        bool f = false;
        while (true) {
            a = a - a / b * b; //计算余数
            if (a == 0)
                break;
            if (mp.count(a)) {
                f = true;
                p = mp[a];
                break;
            }
            mp[a] = c;
            a *= 10;
            ans += '0' + a / b;
            c ++ ;
        }

        if (f) {
            ans.insert(beg + p, "(");
            ans += ')';
        }
        return ans;
    }
};