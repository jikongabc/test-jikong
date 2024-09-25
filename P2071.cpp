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
const int N = 4005, M = 8005;
int n, m;
int h[N], e[M], ne[M], idx;
int match[N][2];
int st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u){
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j]++;
            if(!match[j][0] || dfs(match[j][0])){
                match[j][0] = u;
                return true;
            }
            else if(!match[j][1] || dfs(match[j][1])){
                match[j][1] = u;
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
    cin >> n;
    n *= 2;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        int a, b;
        cin >> a >> b;
        add(i, a), add(i, b);
    }
    int res = 0;
    for (int i = 1; i <= n;i++){
        memset(st, 0, sizeof st);
        if(dfs(i))
            res++;
    }
    cout << res;
    return 0;
}