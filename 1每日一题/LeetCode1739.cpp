class Solution {
public:
    int minimumBoxes(int n) {
        int k = 1;
        int sum = 0;
        while (true) {
            sum += k * (k + 1) / 2; //阶梯型每层可以摆放的盒子
            if (sum >= n) break;
            k ++ ;
        }
        sum -= k * (k + 1) / 2; //多放的一层
        k -- ; //回到上一层
        int ans = k * (k + 1) / 2; //堆成阶梯型占用的格子
        k = 1;
        while (sum < n) {
            sum += k; //每次扩展可以多放的盒子
            k ++ ;
            ans ++ ; //每次扩展占用的格子
        }
        return ans;
    }
};
