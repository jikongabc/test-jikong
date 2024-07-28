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
typedef pair<LL, LL> PLL;
const int N = 2e5 + 10;
int n;
LL x, y;
int res = inf;

struct node{
    int a, b;
} p[N];

bool cmp1(node a,node b){
    if(a.a==b.a){
        return a.b > b.b;
    }
    return a.a > b.a;
}
bool cmp2(node a,node b){
    if(a.b==b.b){
        return a.a > b.a;
    }
    return a.b > b.b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    for (int i = 0; i < n;i++){
        cin >> p[i].a;
    }
    for (int i = 0; i < n;i++){
        cin >> p[i].b;
    }
    sort(p, p + n, cmp1);
    LL sum1 = 0, sum2 = 0;
    int cnt = 0;
    while(sum1<=x && sum2<=y && cnt<n){
        sum1 += p[cnt].a;
        sum2 += p[cnt].b;
        cnt++;
    }
    res = min(res, cnt);

    cnt = 0;
    sum1 = 0, sum2 = 0;
    sort(p, p + n, cmp2);
    while(sum1<=x && sum2<=y && cnt<n){
        sum1 += p[cnt].a;
        sum2 += p[cnt].b;
        cnt++;
    }
    res = min(res, cnt);
    cout << res;
    return 0;
}