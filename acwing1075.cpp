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
const int N = 5e4 + 10;
int n;
int e[N], ne[N], h[N], idx;
int sum[N];
int res;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        int d = dfs(j) + 1;
        if(d>=d1)
            d2 = d1, d1 = d;
        else if(d>d2)
            d2 = d;
    }
    res = max(res, d1 + d2);
    return d1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++){
        for (int j = 2; j <= n / i;j++){
            sum[i * j] += i;
        }
    }
    for (int i = 2; i <= n;i++){
        if(sum[i]<i)
            add(sum[i], i);
    }
    dfs(1);
    cout << res;
    return 0;
}