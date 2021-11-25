/*最多进行k轮
 *设水桶数量n 猪数量x
 *每个猪可能不死、1轮后死、2轮后死...k轮后死 一共k+1种状态
 *x只猪的总状态数量为(k+1)^x
 *总状态数量需大于等于n 由此得出x
 *
 *如何构造？
 *将每桶水编号0~n-1 转换为k+1进制数 第i位上的数表示第几轮喂第i头猪
 *若第y桶水有毒 则其每个数位上的数若不为0 对应的猪会在该轮死去
 *和猪的状态一致 由此推出有毒的水
 */
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(k + 1));
    }
};
