class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        int n = secret.size();
        for (int i = 0; i < n; i ++ )
            if (secret[i] == guess[i]) {
                a ++ ;
                secret[i] = guess[i] = 'a';
            }
        vector<int> c1(10), c2(10);
        for (int i = 0; i < n; i ++ ) {
            if (isdigit(secret[i]))
                c1[secret[i] - '0'] ++ ;
            if (isdigit(guess[i]))
                c2[guess[i] - '0'] ++ ;
        }
        for (int i = 0; i < 10; i ++ ) {
            b += min(c1[i], c2[i]);
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};