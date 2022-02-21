class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        int n = dominoes.size();
        string ans = "";
        for (int i = 0, j; i < n; ) {
            j = i + 1;
            while (j < n && dominoes[j] == '.')
                j ++ ;
            if (j == n) break;
            ans += dominoes[i];
            int cnt = j - i;
            if (dominoes[i] == 'R' && dominoes[j] == 'L')
                if (cnt % 2 == 0) {
                    ans += string(cnt / 2 - 1, 'R');
                    ans += '.';
                    ans += string(cnt / 2 - 1, 'L');
                }
                else {
                    ans += string(cnt / 2, 'R');
                    ans += string(cnt / 2, 'L');
                }
            else if (dominoes[i] == 'R')
                ans += string(cnt - 1, 'R');
            else if (dominoes[j] == 'L')
                ans += string(cnt - 1, 'L');
            else
                ans += string(cnt - 1, '.');
            i = j;
        }
        return ans.substr(1);
    }
};
