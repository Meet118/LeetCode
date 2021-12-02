class Solution {
public:
    unordered_map<string, int> b;
    unordered_map<char, int> c;
    int ans = 1e9;

    string rem(string board) {
        bool f = true;
        int n = board.size();
        while (f) {
            f = false;
            for (int i = 0, j; i < n;) {
                j = i + 1;
                while (j < n && board[j] == board[i]) j ++ ;
                if (j - i >= 3) {
                    f = true;
                    string s = board.substr(0, i) + board.substr(j);
                    board = s;
                    n = board.size();
                    break;
                }
                i = j;
            }
        }
        return board;
    }

    string get() {
        string res = "";
        for (auto &[k, v] : c) 
            if (v > 0) res += k;
        return res;
    }

    int h(string board) { //至少还需要多少次操作
        sort(board.begin(), board.end());
        int res = 0;
        for (int i = 0, j; i < board.size();) {
            j = i + 1;
            while (j < board.size() && board[j] == board[i]) j ++ ;
            if (j - i + c[board[i]] < 3) return 1e9;
            if (j - i <= 2) res += 3 - (j - i);
            i = j;
        }
        return res;
    }

    void dfs(string board, string hand) {
        if (b[board + ' ' + hand] + h(board) >= ans)
            return;
        if (board == "") {
            ans = min(ans, b[board + ' ' + hand]);
            return;
        }
        int n = board.size();
        for (auto& [k, v] : c)
            if (v > 0) {
                c[k] -- ;
                for (int i = 0; i <= n; i ++ ) {
                    if (i && i + 1 < n && board[i] == board[i - 1]) continue;
                    string s = board.substr(0, i) + k + board.substr(i);
                    s = rem(s);
                    string h = s + ' ' + get();
                    if (!b.count(h) || b[h] > b[board + ' ' + hand] + 1) {
                        b[h] = b[board + ' ' + hand] + 1;
                        dfs(s, get());
                    }
                }
                c[k] ++ ;
            }
    }

    int findMinStep(string board, string hand) {
        b[board + ' ' + hand] = 0;
        for (auto i : hand) c[i] ++ ;
        dfs(board, hand);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};
