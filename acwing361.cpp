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
const int N = 1e3 + 10, M = 5e3 + 10;
int n, m;
int wf[N];
int h[N], e[M], ne[M], wt[M], idx;
double dist[N];
bool st[N];
int cnt[N];

void add(int a,int b,int c){
    e[idx] = b, wt[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double mid){
    memset(st, false, sizeof st);
    memset(cnt, 0, sizeof cnt);
    queue<int> q;
    for (int i = 1; i <= n;i++){
        q.push(i);
        st[i] = 1;
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]<dist[t]+wf[t]-mid*wt[i]){
                dist[j] = dist[t] + wf[t] - mid * wt[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j]==n)
                    return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> wf[i];
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    double l = 0, r = 1010;
    while(r-l>1e-4){
        double mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.2lf", r);
    return 0;
}
