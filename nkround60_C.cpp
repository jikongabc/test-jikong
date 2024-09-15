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

const int N = 1e6 + 10;

struct node{
    int x, y;
} a[N];

bool cmp1(node a,node b){
    if(a.x==b.x)
        return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(node a,node b){
    if(a.y==b.y)
        return a.x < b.x;
    return a.y < b.y;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + m, cmp1);
    int t = 0, i = 0;
    int res = 0;
    int cnt1 = 0;
    while(i<m){
        cnt1++;
        while(a[i].x==a[t].x && i<=m)
            i++;
        res = max(res, a[i-1].y - a[t].y);
        t = i;
        if(cnt1>1e5)
            break;
    }
    sort(a, a + m, cmp2);
    t = 0, i = 0;
    int cnt2 = 0;
    while (i < m){
        cnt2++;
        while (a[i].y == a[t].y && i<=m)
            i++;
        res = max(res, a[i-1].x - a[t].x);
        t = i;
        if(cnt2>1e5)
            break;
    }
    if(cnt1>1e5 && cnt2>1e5)
        res = 0;
    cout << res << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}