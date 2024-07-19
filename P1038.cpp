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
typedef pair<PII, int> PIII;
const int N = 110*110/2;
int n, m;
int e[N], ne[N], h[N], w[N], idx;
int d[N];
int b[N];
int c[N];
int q[N];
bool flag;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i]){
            q[++tt] = i;
        }
    }
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(c[t]>0)
                c[j] += w[i] * c[t];
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
    for (int i = 1; i <= n;i++){
        int cc, uu;
        cin >> cc >> uu;
        if(!cc)
            c[i] = cc - uu;
        else
            c[i] = cc;
    }
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        d[v]++, b[u]++;
    }
    topsort();
    // for (int i = 0; i < n;i++){
    //     int j = q[i];
    //     if(c[j]>0){
    //         for (int k = h[j]; ~k;k=ne[k]){
    //             c[e[k]] += c[j] * w[k];
    //         }
    //     }
    // }
        for (int i = 1; i <= n; i++)
        {
            if (!b[i] && c[i] > 0)
            {
                cout << i << ' ' << c[i] << endl;
                flag = 1;
            }
        }
    if(!flag)
        cout << "NULL";
    return 0;
}