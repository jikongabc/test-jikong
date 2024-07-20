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
int tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x){
    for (int i = x; i <= n;i+=lowbit(i))
        tr[i]++;
}

int sum(int x){
    int res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += tr[i];
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int op;
    while(m--){
        cin >> op;
        if(op==1){
            int l, r;
            cin >> l >> r;
            add(l), add(r + 1);
        }
        else{
            int x;
            cin >> x;
            cout << sum(x) % 2 << endl;
        }
    }
    return 0;
}