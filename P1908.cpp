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
const int N = 6e5 + 10;
int n;
int a[N];
int tr[N];
LL res;
struct node{
    int a, id;
} p[N];

bool cmp(node a,node b){
    if(a.a==b.a)
        return a.id < b.id;
    return a.a < b.a;
}

LL lowbit(LL x){
    return x & -x;
}

void add(LL x,LL c){
    for (int i = x; i <= n;i+=lowbit(i))
        tr[i] += c;
}

LL sum(LL x){
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
    for (int i = 1; i <= n;i++){
        a[p[i].id] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int t = a[i];
        res += i - 1 - sum(t - 1);
        add(t, 1);
    }
    cout << res;
    return 0;
}