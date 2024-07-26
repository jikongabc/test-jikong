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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1005;
int n;
int a[N];
int f[N], g[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++){
        f[i] = 1;
        for (int j = 1; j < i;j++)
            if(a[i]>a[j])
                f[i] = max(f[i], f[j] + 1);
    }
    int res = 0;
    for (int i = n; i >= 1;i--){
        g[i] = 1;
        for (int j = n; j > i;j--)
            if(a[i]>a[j]){
                g[i] = max(g[i], g[j] + 1);
            }
        res = max(res, f[i] + g[i] - 1);
    }
    cout << res;
    return 0;
}