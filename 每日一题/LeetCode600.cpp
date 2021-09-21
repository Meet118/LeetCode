/*
数位DP
1.预处理
2.按位考虑（画树形图）
*/
class Solution {
public:
    int findIntegers(int n) {
        int wei = 0, t = n;
        while (t) {
            t /= 2;
            wei ++ ;
        }
        vector<vector<int>> f(wei + 1, vector<int>(2, 0));

        f[1][1] = 1;
        f[1][0] = 1;
        for (int i = 2; i <= wei; i ++ ) { //预处理
            f[i][1] = f[i - 1][0];
            f[i][0] = f[i - 1][0] + f[i - 1][1];
        }

        int ans = 0, pre = 0, flag = 1;
        for (int i = wei - 1; i >= 0; i -- ) { //按位考虑 从高位到低位
            int x = (n >> i) & 1;
            if (x == 1) //此时可选0或1
                ans += f[i + 1][0]; //选0查表
            if (x == 1 && pre == 1) { //选1往后走 两个1相连则跳出
                flag = 0;
                break;
            }
            pre = x;
        }
        if (flag) //一直未跳出说明n合法
            ans ++ ;
        return ans;
    }
};