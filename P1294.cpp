#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 25;
int p[N][N];
bool st[N];
int n, m;
int ans;
int sum;

void dfs(int x){
    for (int i = 1; i <= n;i++){
        if(p[x][i] && !st[i]){
            st[i] = 1;
            sum += p[x][i];
            dfs(i);
            sum -= p[x][i];
        }
    }
    ans = max(ans, sum);
    st[x] = 0;
    // return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b, s;
        cin >> a >> b >> s;
        p[a][b] = s;
        p[b][a] = s;
    }
    for (int i = 1; i <= n;i++){
        st[i] = 1;
        dfs(i);
        memset(st, 0, sizeof st);
    }
    cout << ans;
    return 0;
}
