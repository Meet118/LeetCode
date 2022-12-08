class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0] - 'a' + 1, b = coordinates[1] - '0';
        return (a + b) % 2;
    }
};
