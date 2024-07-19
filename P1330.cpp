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
typedef pair<PII, int> PIII;
const int N = 3e4 + 10, M = 4e5 + 10;
int n, m;
int e[N], ne[N], h[N], idx;
int color[N];
bool flag;
int res;
int a, b;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int x,int c){
    color[x] = c;
    for (int i = h[x]; ~i;i=ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j,3-c))
                return false;
        }
        else if(color[j]==c)
            return false;
    }
    if(c==1 )
        a++;
    else if(c==2)
        b++;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n;i++){
        a = 0, b = 0;
        if(!color[i]){
            if(!dfs(i,1)){
                flag = 1;
            }
            res += min(a, b);
        }
    }
    if(flag)
        cout << "Impossible";
    else{
        int a = 0, b = 0;
        for (int i = 1; i <= n;i++){
            res += (color[i] == 1);
        }
        res = min(res, n - res);
        cout << res;
    }
    return 0;
}