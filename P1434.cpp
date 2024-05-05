#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 110;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m;
int p[N][N];
int dp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            int flag = (i - 1) * m + j;//    n=5 m=5 (3,4)-->14      (4,5)-->20
            cin >> p[i][j];
            dp[i][j] = 1;
            q.push({p[i][j], flag});
        }
    }
    int ans = -inf;
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int dis = t.first, ver = t.second;
        int x, y;
        // x = ver / m, y = ver % m;
        if(ver%m!=0){
            x = ver / m + 1, y = ver % m;
        }
        else{
            x = ver / m, y = m;
        }
        // cout << x << ' ' << y << endl;
        for (int i = 0; i < 4;i++){
            int a = x + dx[i], b = y + dy[i];
            if(p[a][b]>=dis)
                continue;
            dp[x][y] = max(dp[x][y], dp[a][b] + 1);
        ans=max(ans,dp[x][y]);
        }
        // if(p[x-1][y]<dis)
        //     dp[x][y] = max(dp[x][y], dp[x - 1][y] + 1);
        // if (p[x + 1][y] < dis)
        //     dp[x][y] = max(dp[x][y], dp[x + 1][y] + 1);
        // if(p[x][y-1]<dis){
        //     dp[x][y] = max(dp[x][y], dp[x][y - 1] + 1);
        // }
        // if(p[x][y+1]<dis){
        //     dp[x][y] = max(dp[x][y], dp[x][y + 1] + 1);
        // }
        ans = max(ans, dp[x][y]);
    }
    cout << ans;
    return 0;
}
//if(dp[i][j]>dp[][])
//dp[i][j]=max(dp[i-1][j],dp[i+1][j],dp[i][j-1],dp[i][j+1])+1
