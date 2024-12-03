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
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 505, M = 1e5 + 10;

int n1, n2, m;
int e[M], ne[M], h[N], idx;
bool st[N];
int match[N];
int res;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int x){
    for (int i = h[x]; ~i;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = 1;
            if(match[j]==0 || dfs(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n1;i++){
        memset(st, false, sizeof st);
        if(dfs(i))
            res++;
    }
    cout << res;
    return 0;
}