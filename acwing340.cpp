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
const int N = 1010, M = 2e4 + 10;
int n, m, k;
int dist[N];
int e[M], h[N], w[M], ne[M], idx;
bool st[N];
deque<int> q;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(int x){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[1] = 0;
    q.push_back(1);
    while(!q.empty()){
        int t = q.front();
        q.pop_front();
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            int dis = w[i] > x;
            if(dist[j]>dist[t]+dis){
                dist[j] = dist[t] + dis;
                if(!dis)
                    q.push_front(j);
                else
                    q.push_back(j);
            }
        }
    }
    return dist[n] <= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int l = -1, r = 1e6 + 1;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if(r==1e6+1)
        r = -1;
    cout << r;
    return 0;
}
