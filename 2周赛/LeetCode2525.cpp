class Solution {
public:
    string categorizeBox(int a, int b, int c, int m) {
        bool f1 = false, f2 = false;
        long long t = (long long)a * b * c;
        if (a >= 1e4 || b >= 1e4 || c >= 1e4 || t >= 1e9)
            f1 = true;
        if (m >= 100)
            f2 = true;
        if (f1 && f2) return "Both";
        else if (!f1 && !f2) return "Neither";
        else if (f1 && !f2) return "Bulky";
        else return "Heavy";
    }
};

