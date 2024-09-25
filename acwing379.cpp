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
const int N = 205;
int n, m;
bool d[N][N];
int match[N];
bool st[N];

bool dfs(int u){
    for (int i = 1; i <= n;i++){
        if(d[u][i] && !st[i]){
            st[i] = true;
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
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        d[a][b] = true;
    }
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                d[i][j] |= d[i][k] & d[k][j];
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n;i++){
        memset(st, false, sizeof st);
        if(dfs(i))
            res++;
    }
    cout << n - res;
    return 0;
}