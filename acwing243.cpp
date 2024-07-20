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
const int N = 2e5 + 10;
int n, m;
int a[N];
LL tr1[N], tr2[N];

int lowbit(int x){
    return x & -x;
}

void add(LL tr[],int x,LL c){
    for (int i = x; i <= n;i+=lowbit(i))
        tr[i] += c;
}

LL sum(LL tr[],int x){
    LL res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += tr[i];
    return res;
}

LL pre(int x){
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        int b = a[i] - a[i - 1];
        add(tr1, i, b);
        add(tr2, i, (LL)b * i);
    }
    string op;
    while(m--){
        cin >> op;
        if (op == "C")
        {
            int l, r, d;
            cin >> l >> r >> d;
            add(tr1, l, d), add(tr2, l, l * d);
            add(tr1, r + 1, -d), add(tr2, r + 1, -(r + 1) * d);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << pre(r) - pre(l - 1) << endl;
        }
    }

    return 0;
}