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
const int N = 676, M = 1e5 + 10;
int n = 676, m;
int h[N], e[M], ne[M], w[M], idx;
double dist[N];
bool st[N];
int cnt[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double mid){
    queue<int> q;
    memset(st, false, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0, sizeof dist);
    for (int i = 0; i < n;i++){
        q.push(i);
        st[i] = 1;
    }
    int count = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]<dist[t]+w[i]-mid){
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                if(++count>=10000 || cnt[j]>=n)
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
    while(cin>>m,m){
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0; i < m;i++){
            string s;
            cin >> s;
            int len = s.size();
            if(len>=2){
                int a = (s[0]-'a') * 26 + (s[1]-'a'), b = (s[len - 2]-'a') * 26 + (s[len - 1]-'a');
                add(a, b, len);
            }
        }
        if(!check(0)){
            cout << "No solution\n";
            continue;
        }
        double l = 0, r = 1000;
        while(r-l>1e-4){
            double mid = (l + r) / 2;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.2lf\n", l);
    }
    return 0;
}
