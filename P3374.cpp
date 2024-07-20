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
const int N = 5e5 + 10;
int n, m;
int a[N];
int tr[N];

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
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        add(i, a[i]);
    }
    int op;
    while(m--){
        cin >> op;
        if(op==1){
            int x, k;
            cin >> x >> k;
            add(x, k);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << endl;
        }
    }
    return 0;
}