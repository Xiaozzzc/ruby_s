#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


class dpLinear {
public:
    /*
     * 2188. 完成比赛的最少时间
     * 给出 tires 数组，其中每一个元素第一个数字表示 使用轮胎 第一圈需要耗费的时间，第二个数字 表示不换轮胎后面需要乘的系数
     * 如 [2, 3] 第一圈需要 2 秒，第二圈 2 * 3 = 6 秒，第三圈 6 * 3 = 18 秒
     * 每次换轮胎需要 changeTime 时间，总共要跑 numLaps 圈，求花费的最少时间
     *
     * e.g.
     * tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
     * -> 21
     * 解释：
     * 第 1 圈：使用轮胎 0 ，耗时 2 秒
     * 第 2 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒
     * 第 3 圈：耗费 5 秒换一条新的轮胎 0 ，然后耗时 2 秒完成这一圈
     * 第 4 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒
     * 总耗时 = 2 + 6 + 5 + 2 + 6 = 21 秒
     */
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
        // 2 ^ 17 = 131072 大于 changeTime 的取值范围 10 ^ 5。故选择 17
        // 初始化一个大小为 18 的数组，初始值为 INT_MAX / 2
        // 除二是防止下面计算状态转移时溢出
        // minSec[x] 表示 完成 x 轮，不换轮胎 所需要的最少时间
        vector<int> minSec(18, INT_MAX / 2);
        for (auto &tire : tires) {
            long time = tire[0];
            for (int x = 1, sum = 0; time <= changeTime + tire[0]; ++x) {
                sum += time;
                minSec[x] = min(minSec[x], sum);
                time *= tire[1];
            }
        }

        vector<int> f(numLaps + 1, INT_MAX);  // f[i] 表示跑 i 圈所需要的最少时间
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            // f[i] 最多从 f[i - 17] 进化而来
            for (int j = 1; j <= min(17, i); ++j)
                f[i] = min(f[i], f[i - j] + minSec[j]);
            f[i] += changeTime;
        }
        return f[numLaps];
    }
};