#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(){
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; i != -1;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[t]+w[i]){
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
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();
    if(t==inf)
        cout << "impossible";
    else
        cout << t;
    return 0;
}