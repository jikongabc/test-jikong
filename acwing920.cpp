#include <iostream>
#include <algorithm>
#include <sstream>
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
const int N = 510, M = N * N;
typedef pair<int, int> PII;
int e[M], w[M], h[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m;
int a[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second;
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    string line;
    getline(cin, line);
    memset(h, -1, sizeof h);
    while(m--){
        getline(cin, line);
        stringstream ssin(line);
        int num;
        int cnt = 0;
        while(ssin>>num){
            a[cnt++] = num;
        }
        for (int i = 0; i < cnt-1;i++){
            for (int j = i + 1; j < cnt; j++)
            {
                add(a[i], a[j], 1);
            }
        }
    }
    int t = dijkstra();
    // for (int i = 1; i <= n;i++){
    //     cout << dist[i] << ' ';
    // }
        if(t==inf)
            cout << "NO";
        else
            cout << max(t-1, 0);
        return 0;
}