#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<deque>
#include<vector>
#include<map>
#include<set>
using namespace std;
using LL = long long;
typedef pair<int, int> PII;
const int N = 505;
int n, m;
int cnt_flag = 0;
int high[N][N];
bool flag[N][N];
bool st[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
queue<PII> q;
int x1, y1;
bool bfs(int x){
    q.push({x1, y1});
    st[x1][y1] = 1;
    int cnt = 1;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<1|| a>n||b<1||b>m)
                continue;
            if(abs(high[t.first][t.second]-high[a][b])>x)
                continue;
            if(st[a][b])
                continue;
            q.push({a, b});
            st[a][b] = 1;
            if(flag[a][b]){
                cnt++;
                if(cnt==cnt_flag)
                    return true;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> high[i][j];
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> flag[i][j];
            if(flag[i][j])
                cnt_flag++;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(flag[i][j]){
                x1 = i,y1 = j;
                break;
            }
        }
    }
    LL l = 0, r = 1e9 + 10;
    int mid,ans;
    while(l<=r){
        memset(st, 0, sizeof st);
        while(!q.empty())
            q.pop();
        mid = (l + r) >> 1;
        if(bfs(mid)){
            r = mid-1;
            ans = mid;
        }
        else
            l = mid+1;
    }
    cout << ans;
    return 0;
}