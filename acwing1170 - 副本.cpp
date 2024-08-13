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
const int N = 1e3 + 10, M = 1e5 + 10;
int n, m1, m2;
int dist[N];
int cnt[N];
bool st[N];
int h[N], e[M], ne[M], w[M] ,idx;

void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa(int x){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    memset(cnt, 0, sizeof cnt);
    queue<int> q;
    for (int i = 1; i <= x;i++){
        q.push(i);
        st[i] = 1;
        dist[i] = 0;
    }
    while(!q.empty()){
        int t =q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if (dist[j] > dist[t]+w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j]>=n)
                    return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m1 >> m2;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n;i++)
        add(i + 1, i, 0);
    while (m1--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
        add(a, b, c);
    }
    while(m2--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a>b)
            swap(a, b);
        add(b, a, -c);
    }
    if(spfa(n))
        cout << -1;
    else{
        spfa(1);
        if(dist[n]==inf)
            cout << -2;
        else
            cout << dist[n];
    }
    return 0;
}
