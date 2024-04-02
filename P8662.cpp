#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<unordered_map>
#include<vector>
#include<deque>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1005;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<PII> q;
int n;
char ch[N][N];
bool st[N][N];
int cnt, cnt1;
void bfs(int x,int y){
    q.push({x, y});
    st[x][y] = 1;
    bool judgee = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        bool judge = 0;
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(st[a][b])
                continue;
            if(a<0 || b<0 || a>=n || b>=n)
                continue;
            if(ch[a][b]!='#'){
                ch[t.first][t.second] = '*';
                judge = 1;
                continue;
            }
            st[a][b] = 1;
            q.push({a, b});
        }
        if (!judge)
            judgee = 1;
    }
    if(judgee)
        cnt++;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> ch[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(ch[i][j]=='#' && !st[i][j]){
                bfs(i, j);
                cnt1++;
            }
        }
    }
    // cout << cnt1 << ' ' << cnt2 << endl;
    cout << cnt1-cnt;
    return 0;
}