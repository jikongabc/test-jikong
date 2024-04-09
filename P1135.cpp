#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 205;
int n, start, end1;
int k[N];
int cnt;
int ans = 0x3f3f3f3f;
int d[] = {-1, 1};
int st[N];
void dfs(int x,int cnt){
    st[x] = cnt;
    for (int i = 0; i < 2;i++){
        int vis = x + d[i] * k[x];
        if(vis>0 && vis<=n && cnt+1<st[vis]){
            dfs(vis, cnt + 1);
        }
    }
    // int v = x - k[x];
    // if (1 <= v && cnt + 1 < st[v] ) 
    //     dfs(v, cnt + 1);
    // v = x + k[x];
    // if (v <= n && cnt + 1 < st[v]) 
    //     dfs(v, cnt + 1);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(st, 0x3f, sizeof st);
    cin >> n >> start >> end1;
    for (int i = 1; i <= n;i++){
        cin >> k[i];
    }
    dfs(start,0);
    // if(st[end1]==0x3f)
    //     cout << -1;
    // else
    //     cout << st[end1];
    cout << (st[end1] == 0x3f3f3f3f ? -1 : st[end1]);
    return 0;
}