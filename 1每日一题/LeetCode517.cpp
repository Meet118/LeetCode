/*
贪心
最少的操作步数即 对于某个洗衣机 它的所有操作次数即答案
若不存在这样的洗衣机A 则存在A运送 B不动 然后B运送 A不动 但是它们是可以并行的
故一定存在这样的洗衣机A
在最优情况下 需要满足所有洗衣机 故操作次数最多的是答案
*/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for (int x : machines)
            sum += x;
        int n = machines.size();
        if (sum % n != 0)
            return -1;
        int t = 0, ans = 0, avg = sum / n;
        for (int i = 0; i < n; i ++ ) {

            int l = max(0, avg * i - t);
            t += machines[i];
            int r = max(0, avg * (n - i - 1) - sum + t);
            ans = max(ans, l + r);
        }

        return ans;
    }
};