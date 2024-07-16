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
const int N = 1e5 + 10, M = 4e5 + 10;
int n, m;
int e[N], ne[N], h[N], idx;
int q[N];
int d[N];
int res[N];
bool st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i]){
            q[++tt] = i;
            res[i] = 1;
        }
            
    }
    while(hh<=tt){
        int t = q[hh++];
        int count = 0;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            res[j] = max(res[j], res[t] + 1);
            if(--d[j]==0){
                q[++tt] = j;
            }
        }
        // if(count>1)
        //     cnt--;
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
    }
    topsort();
    for (int i = 1; i <= n;i++){
        cout << res[i] << endl;
    }
        return 0;
}