#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10;
int n, m;
LL a[N];
int e[N], ne[N], h[N],idx;
int d[N];
LL ti[N];
int q[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i]){
            q[++tt] = i;
            ti[i] = a[i];
        }    
    }
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            ti[j] = max(ti[j], a[j] + ti[t]);
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
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    topsort();
    LL res = 0;
    for (int i = 1; i <= n;i++){
        res = max(res, ti[i]);
    }
    cout << res;
    return 0;
}
