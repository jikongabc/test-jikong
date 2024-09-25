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
const int N = 2005, M = 4005;
int n, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
int sum[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u){
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = 1;
            if(!match[j] || dfs(match[j])){
                match[j] = u;
                sum[u] = j;
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
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m;i++){
        int a, b;
        cin >> a >> b;
        add(i, a+1), add(i, b+1);
    }
    int res = 0;
    for (int i = 1; i <= m;i++){
        memset(st, false, sizeof st);
        if(dfs(i))
            res++;
        else
            break;
    }
    cout << res << endl;
    for (int i = 1; i <= res;i++){
        cout << sum[i] - 1 << endl;
    }
        return 0;
}