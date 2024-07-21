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
const int N = 1e5 + 10;
int n;
int res;
int a[N];
LL tr[N];
int l[N], r[N];

struct node{
    int a, id;
} p[N];

bool cmp(node a,node b){
    if(a.a==b.a)
        return a.id < b.id;
    return a.a < b.a;
}

int lowbit(int x){
    return x & -x;
}

void add(int x,int c){
    for (int i = x; i <= n;i+=lowbit(i))
        tr[i] += c;
}

LL sum(int x){
    LL res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += tr[i];
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> p[i].a;
        p[i].id = i;
    }
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        a[p[i].id] = i;
    for (int i = 1; i <= n; i++){
        int t = a[i];
        l[i] = sum(n) - sum(a[i]);
        add(t, 1);
    }
    memset(tr, 0, sizeof tr);
    for (int i = n; i >= 1;i--){
        int t = a[i];
        r[i] = sum(n) - sum(a[i]);
        add(t, 1);
    }
    for (int i = 1; i <= n; i++){
        int maxn = max(l[i], r[i]);
        int minn = min(l[i], r[i]);
        if(maxn>minn*2)
            res++;
    }
    cout << res;
    return 0;
}
