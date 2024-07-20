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
LL tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int c){
    for (int i = x; i <= n;i+=lowbit(x))
        tr[i] += c;
}

LL sum(int x){
    LL res;
    for (int i = x; i;i-=lowbit(i))
        res += tr[i];
    return res;
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
        add(i, a[i] - a[i - 1]);
    }
    string op;
    while(m--){
        cin >> op;
        if (op == "C")
        {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d), add(r + 1, -d);
        }
        else
        {
            int x;
            cin >> x;
            cout << sum(x) << endl;
        }
    }
    return 0;
}