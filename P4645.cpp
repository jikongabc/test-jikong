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
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 5e4 + 10, M = 4e5 + 10;
const int mod = 1e9;
int n, m;
int h[N], rh[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
int dp[N];
bool mk[N][2];
int din[N];

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
	mk[u][0] = 1;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!mk[j][0]) dfs(j);
		din[j]++;
	}
}

void dfs1(int u){
	mk[u][1] = 1;
	for(int i = rh[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!mk[j][1]) dfs1(j);
	}
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    in_stk[u] = true;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(in_stk[j]) low[u] = min(low[u], dfn[j]);
    }
    if(dfn[u] == low[u]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt] ++;
        }while(y != u);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(rh, -1,sizeof rh);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(h, a, b);
        add(rh, b, a);
        // din[b]++;
    }
    dfs(1);
    dfs1(2);
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i = 1; i <= n; i++){
    	if(mk[i][0] && mk[i][1] && sz[id[i]] > 1){
    		cout << "inf";
    		return 0;
    	}
    }
    dp[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(mk[j][1]){
            	dp[j] = (dp[j] + dp[t]) % mod;
           	 	if(--din[j] == 0) q.push(j);
            }
            
        }
    }
    cout << dp[2];
    return 0;
}
