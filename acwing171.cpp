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
const int N = 50;
int m, n;
int w[N];
int res;
int cnt;
int weight[1 << 23];

void dfs1(int u,int s){
    if(u==n/2){
        weight[cnt++] = s;
        return;
    }
    dfs1(u + 1, s);
    if((LL)s+w[u]<=m)
        dfs1(u + 1, s + w[u]);
    return;
}

void dfs2(int u,int s){
    if(res==m)
        return;
    if(u==n){
        int l = 0, r = cnt - 1;
        while(l<r){
            int mid = l + r + 1 >> 1;
            if((LL)weight[mid]+s<=m)
                 l = mid;
            else
                r = mid - 1;
        }
        res = max(res, weight[l] + s);
        return;
    }
    dfs2(u + 1, s);
    if((LL)s+w[u]<=m)
        dfs2(u + 1, s + w[u]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n;i++)
        cin >> w[i];
    dfs1(0, 0);
    sort(weight, weight + cnt);
    cnt = unique(weight, weight + cnt) - weight;
    dfs2(n / 2, 0);
    cout << res;
    return 0;
}
