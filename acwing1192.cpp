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
const int N = 1e4 + 10, M = 2e4 + 10;
int n, m;
int e[M], h[N], ne[M], idx;
int dist[N];
int d[N];
int q[M];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i])
            q[++tt] = i;
    }
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(--d[j]==0)
                q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        dist[i] = 100;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(b, a);
        d[a]++;
    }
    if(!topsort())
        cout << "Poor Xed\n";
    else{
        for (int i = 0; i < n;i++){
            int j = q[i];
            for (int k = h[j]; ~k;k=ne[k]){
                int l = e[k];
                if(dist[l]<dist[j]+1){
                    dist[l] = dist[j] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n;i++)
            res += dist[i];
        cout << res << endl;
    }
    return 0;
}
