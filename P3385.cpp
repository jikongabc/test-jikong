#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 1e5+10;
int n, m;
int e[N], h[N], w[N], ne[N], idx;
int dist[N];
bool st[N];
int cnt[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
    queue<int> q;
    q.push(1);
    st[1] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j]>=n){
                    return true;
                }
                if(!st[j]){
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(dist, inf, sizeof dist);
        memset(st, false, sizeof st);
        memset(h, -1, sizeof h);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
        while(m--){
            int a, b, w;
            cin >> a >> b >> w;
            if(w>=0)
                add(a, b, w), add(b, a, w);
            else
                add(a, b, w);
        }
        if(spfa())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}