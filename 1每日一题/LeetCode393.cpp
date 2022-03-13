class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        int cnt = 0; //连续1的个数
        while (i < n) {
            if (cnt) {
                if (!(((data[i] >> 7 & 1) == 1) && ((data[i] >> 6 & 1) == 0)))
                    return false;
                cnt -- ;
            }
            else {
                if ((data[i] >> 7 & 1) == 0)
                    cnt = 0;
                else {
                    int idx = 7;
                    while (idx >= 0 && (data[i] >> idx & 1) == 1)
                        idx -- , cnt ++ ;
                    if (cnt > 4)
                        return false;
                    cnt -- ;
                    if (cnt == 0)
                        return false;
                }
            }
            i ++ ;
        }
        return cnt == 0;
    }
};
