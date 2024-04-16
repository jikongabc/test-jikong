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
const int N = 2e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int dist[N];
queue<int> q;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(){
    memset(dist, -1, sizeof dist);
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1;i=ne[i]){
            int j = e[i];
            if(dist[j]>=0)
                continue;
            dist[j] = dist[t] + 1;
            q.push(j);
        }
    }
    return dist[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}