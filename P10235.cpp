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
int n, k;
int a[N];
int tr[N];

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

bool check(LL x){
    int L = 1;
    LL sumn = 0, cnt = 1;
    for (int i = 1; i <= n; i++){
        int t = a[i];
        LL ph = sum(n) - sum(t);
        if(sumn+ph<=x){
            sumn += ph;
        }
        else{
            cnt++;
            sumn = 0;
            for (int j = L; j <= i - 1;j++)
                add(a[j], -1);
            L = i;
        }
        add(t, 1);
    }
    for (int i = L; i <= n;i++)
        add(a[i], -1);
    return cnt <= k;
} 

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin>>p[i].a;
        p[i].id = i;
    }
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n;i++)
        a[p[i].id] = i;
    LL l = 0, r = 1e10;
    while(l<r){
        LL mid = l + r >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
