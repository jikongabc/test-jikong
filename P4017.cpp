#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 5010, M = 5e5 + 10;
const int mod = 80112002;
int n, m;
int h[M], e[M], ne[M], idx;
int d[N], d1[N];
int q[N];
int res[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i]){
            q[++tt] = i;
            res[i]++;
        }
    }
        while(hh<=tt){
            int t = q[hh++];
            for (int i = h[t]; ~i;i=ne[i]){
                int j = e[i];
                res[j] = (res[j] + res[t]) % mod;
                if(--d[j]==0){
                    q[++tt] = j;
                }
            }
        }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
        d1[a]++;
    }
    topsort();
    int ans = 0;
    for (int i = 1; i <= n;i++){
        if(d1[i]==0)
            ans = (ans + res[i]) % mod;
    }
    cout << ans % mod;
    return 0;
}