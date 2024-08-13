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
#include <bitset>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 3e4 + 10;
int n, m;
int e[N], ne[N], h[N], idx;
int d[N];
int q[N];
bitset<N> dp[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(!d[i])
            q[++tt] = i;
    }
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(--d[j]==0)
                q[++tt] = j;
        }
    }
}

int main()
{
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
    for (int i = n - 1; ~i; i--)
    {
        int t = q[i];
        dp[t][t] = 1;
        for (int j = h[t]; ~j; j = ne[j])
        {
            int k = e[j];
            dp[t] |= dp[k];
        }
    }
    for (int i = 1; i <= n;i++)
        cout << dp[i].count() << endl;
    return 0;
}
