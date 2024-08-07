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
int n, m;
int h[N], cnt;

void down(int u){
    int t = u;
    if(u*2<=cnt && h[u*2]<h[t])
        t = u * 2;
    if(u*2+1<=cnt && h[u*2+1]<h[t])
        t = u * 2 + 1;
    if(u!=t){
        swap(h[u], h[t]);
        down(t);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> h[i];
    cnt = n;
    for (int i = n / 2; i;i--)
        down(i);
    while(m--){
        cout << h[1] << ' ';
        h[1] = h[cnt--];
        down(1);
    }
        return 0;
}