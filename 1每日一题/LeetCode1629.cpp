class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int m = releaseTimes[0];
        for (int i = 1; i < keysPressed.size(); i ++ ) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if (t > m) {
                m = t;
                ans = keysPressed[i];
            }
            else if (t == m && keysPressed[i] > ans)
                ans = keysPressed[i];
        }
        return ans;
    }
};
