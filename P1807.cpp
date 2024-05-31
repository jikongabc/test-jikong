#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5+10, M = 1e6 + 10;
int n, m;
int e[N], h[N],ne[N], w[N], idx;
LL dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

LL spfa(){
    memset(dist, -inf, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = 1;
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]<dist[t]+w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    return dist[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(m==0 ){
        cout << -1;
        return 0;
    }
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    LL res= spfa();
    if(res<=-inf)
        cout << -1;
    else
        cout << res;

    return 0;
}