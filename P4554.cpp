#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
using namespace std;
using LL = long long;
typedef pair<int, int> PII;
const int N = 505;
int n, m;
char ch[N][N];
int s[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
deque<PII> q;
int x1, y1, x2, y2;

int bfs(){
    memset(s, -1, sizeof s);
    q.push_back({x1, y1});
    s[x1][y1] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop_front();
        char c = ch[t.first][t.second];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || b < 0 || a > n || b > m)
                continue;
            if (s[a][b] >= 0)
                continue;
            if (ch[a][b] == c)
            {
                s[a][b] = s[t.first][t.second];
                q.push_front({a, b});
            }
            else
            {
                s[a][b] = s[t.first][t.second] + 1;
                q.push_back({a, b});
            }
            if (a == x2 && b == y2)
                return s[a][b];
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m){
        if(!n && !m)
            break;
        q.clear();
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                cin >> ch[i][j];
            }
        }
        cin >> x1 >> y1 >> x2 >> y2;
        int ans=bfs();
        cout << ans << endl;
    }
    return 0;
}