// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <cmath>
// #include <unordered_map>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// typedef pair<double, int> PDI;
// const int N = 100005;
// const int dx[] = {-1, 0, 1, 0};
// const int dy[] = {0, 1, 0, -1};
// int n;
// int a[N];
// double b[N];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     double maxn = 99999.0;
//     int flag;
//     int sum = 0;
//     for (int i = 1; i <= n;i++){
//         cin >> a[i];
//         sum += a[i];
//     }
//     double num = sum / n*1.0;
//     for (int i = 1; i <= n;i++){
//         b[i] = abs(a[i] - num);
//         if(b[i]<maxn){
//             maxn = b[i];
//             flag = i;
//         }
//     }
//     sum = 0;
//     for (int i = 1; i <= n; i++){
//         sum += (flag - i) * (flag - i) * a[i];
//     }
//     cout << sum;
//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], f[N], left_sum[N], right_sum[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    for (int i = n; i >= 1; i--)
        f[i - 1] += f[i] + (a[i] - a[i - 1]) * (n - i);
    for (int i = 2; i <= n; i++)
        left_sum[i] = left_sum[i - 1] + (i - 1) * (f[i] - f[i - 1]);
    for (int i = n - 1; i >= 1; i--)
        right_sum[i] = right_sum[i + 1] + (n - i) * (f[i + 1] - f[i]);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        ans = min(ans, left_sum[i] + right_sum[i] + f[i]);
    cout << ans << endl;
    return 0;
}