#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, M = 1e6 + 10;
LL n, d;
int x[N], y[N];
LL fx[N], fy[N];
LL cnt[M];
LL res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n;i++){
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    for (int i = 1; i <= n;i++){
        fx[i] = fx[i - 1] + x[i];
        fy[i] = fy[i - 1] + y[i];
    }
    // 枚举x值
    for (int i = -2e6; i <= 2e6; i++)
    {
        LL t = upper_bound(x + 1, x + 1 + n, i) - x - 1;        // 小于等于x
        LL dist = t * i - fx[t] + fx[n] - fx[t] - (i * (n - t));//x方向曼哈顿距离和
        if(dist>d)
            continue;
        cnt[dist]++;
    }
    for (int i = 1; i <= d;i++){
        cnt[i] += cnt[i - 1];
    }
    // 枚举y值
    for (int i = -2e6; i <= 2e6; i++)
    {
        LL t = upper_bound(y + 1, y + 1 + n, i) - y - 1;
        LL dist = t * i - fy[t] + fy[n] - fy[t] - (i * (n - t));
        if (dist > d)
            continue;
        res += cnt[d - dist];
    }
    cout << res << endl;
        return 0;
}
