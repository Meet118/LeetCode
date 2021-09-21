class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0; //找规律 1 2 3时必胜 4时必败 后面的任何数都可以转换成必败或必胜的状态
    }
};