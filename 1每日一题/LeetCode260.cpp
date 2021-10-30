//设答案为a b 则所有数异或结果为a^b 由于a!=b a^b!=0 按第k位为0或1分类 因为只有a b不一样 异或其中一类即为a 剩下为b
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (int x : nums)
            s ^= x;
        int k = 0;
        while ((s >> k & 1) == 0) k ++ ;
        int t = 0;
        for (int x : nums)
            if ((x >> k & 1) == 0)
                t ^= x;
        return {t, s ^ t};
    }
};