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
const int N = 105;
int n, m, k;
bool g[N][N];
int match[N];
bool st[N];

bool dfs(int u){
    for (int i = 1; i < m;i++){
        if(g[u][i] && !st[i]){
            st[i] = 1;
            if(!match[i] || dfs(match[i])){
                match[i] = u;
                return true;
            }
        } 
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n,n){
        cin >> m >> k;
        memset(match, 0, sizeof match);
        memset(g, 0, sizeof g);
        while(k--){
            int t, a, b;
            cin >> t >> a >> b;
            if(!a||!b)
                continue;
            g[a][b]  = 1;
        }
        int res = 0;
        for (int i = 1; i < n;i++){
            memset(st, false, sizeof st);
            if(dfs(i))
                res++;
        }
        cout << res << endl;
    }

    return 0;
}