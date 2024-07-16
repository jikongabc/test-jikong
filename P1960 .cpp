#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e4 + 10, M = 2e5 + 10;
int n, m;
int e[M], ne[M], h[M], idx;
int d[N];
int q[N];
int hh = 0, tt = -1;
bool flag;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    for (int i = 1; i <= n;i++){
        if(!d[i])
            q[++tt] = i;
    }
    while(hh<=tt){
        int cnt = 0;
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(--d[j]==0){
                q[++tt] = j;
                cnt++;
                if(cnt>1)
                    flag = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    topsort();
    for (int i = 0; i <= tt;i++)
        cout << q[i] << endl;
    if(flag)
        cout << 1 << endl;
    else
        cout << 0 << endl;
        return 0;
}