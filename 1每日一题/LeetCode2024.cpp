class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        int cnt = 0;
        for (int i = 0, j = 0; i < answerKey.size(); i ++ ) {
            if (answerKey[i] == 'T')
                cnt ++ ;
            while (cnt > k && j <= i) {
                if (answerKey[j] == 'T')
                    cnt -- ;
                j ++ ;
            }
            ans = max(i - j + 1, ans);
        }
        cnt = 0;
        for (int i = 0, j = 0; i < answerKey.size(); i ++ ) {
            if (answerKey[i] == 'F')
                cnt ++ ;
            while (cnt > k && j <= i) {
                if (answerKey[j] == 'F')
                    cnt -- ;
                j ++ ;
            }
            ans = max(i - j + 1, ans);
        }
        return ans;
    }
};
