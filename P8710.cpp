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
int fa[N];
int d[N];

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int op, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    while (m--)
    {
        cin >> op >> a >> b;
        int pa = find(a), pb = find(b);
        if (op == 1)
        {
            if(pa!=pb){
                fa[pa] = pb;
                d[b] += d[a];
            }
        }
        else{
            d[pa] += b;
        }
    }
    for (int i = 1; i <= n;i++){
        int pi = find(i);
        cout << d[i] << ' ';
    }
        return 0;
}