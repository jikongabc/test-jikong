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
const int N = 20;
int n, m;
int a[N];
int res = inf;
int sum[N];

void dfs(int u,int k){
    if(k>res)
        return;
    else if(u==n){
        res = k;
        return;
    }
    for (int i = 0; i < k;i++){
        if(sum[i]+a[u]<=m){
            sum[i] += a[u];
            dfs(u + 1, k);
            sum[i] -= a[u];
        }
    }
    sum[k++] = a[u];
    dfs(u + 1, k + 1);
    sum[k] -= a[u];
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i< n;i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    dfs(0, 0);
    cout << res;
    return 0;
}
