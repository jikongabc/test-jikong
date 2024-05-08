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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 25;
int n, m;
int w[N];
int sum[N];
int ans = N;

void dfs(int u,int k){
    if(k>=ans)
        return;
    if(u==n){
        ans = k;
        return;
    }
    for (int i = 0; i < k;i++){
        if(sum[i]+w[u]<=m){
            sum[i] += w[u];
            dfs(u + 1, k);
            sum[i] -= w[u];
        }
    }
    sum[k] = w[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> w[i];
    }
    sort(w, w + n);
    reverse(w, w + n);
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}