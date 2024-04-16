#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10;
int n;
int h[N], e[N], ne[N], idx;
bool st[N];
int ans = N;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    st[u] = 1;
    int res = 0, sum = 1;
    for (int i = h[u]; i != -1;i=ne[i]){
        int j = e[i];
        if(st[j])
            continue;
        int s = dfs(j);
        res = max(res, s);
        sum += s;
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}