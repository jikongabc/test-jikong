#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 10005;
int n, m;
int s, t;
int x[N], y[N];
int h[N], e[N], ne[N], idx;
double w[N];
double dist[N];
bool st[N];

void add(int a,int b,double c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

double spfa(){
    memset(dist, 9999999, sizeof dist);
    dist[s] = 0.0;
    queue<int> q;
    q.push(s);
    st[s] = 1;
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
    return dist[t];
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> x[i] >> y[i];
    }
    memset(h, -1, sizeof h);
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        double w = sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
        add(a, b, w), add(b, a, w);
    }
    cin >> s >> t;
    printf("%.2lf", spfa());
    return 0;
}