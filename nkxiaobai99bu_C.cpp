#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1005;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n, m;
int st[N][N];
queue<PII> q;
string s[N];
int x, y, xe, ye;
int maxx, maxy, minx, miny;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
        s[i] = "#" + s[i];
        for (int j = 1; j <= m;j++){
            if(s[i][j]=='S')
                x = i, y = j;
            else if(s[i][j]=='E')
                xe = i, ye = j;
        }
    }
    q.push({x, y});
    st[x][y] = 1;
    maxx = x, minx = x, maxy = y, miny = y;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        maxx = max(maxx, t.first);
        maxy = max(maxy, t.second);
        minx = min(minx, t.first);
        miny = min(miny, t.second);
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(st[a][b]==1)
                continue;
            if(a<1 || b<1 ||a>n || b>m)
                continue;
            if(s[a][b]=='#')
                continue;
            st[a][b] = 1;
            if(a==xe && b==ye){
                cout << "YES";
                return 0;
            }
            q.push({a, b});
        }
    }
    maxx++, maxy++, minx--, miny--;
    while(!q.empty())
        q.pop();
    q.push({xe, ye});
    st[xe][ye] = 2;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(t.first>=minx && t.first<=maxx && t.second>=miny && t.second<=maxy) {
            cout << "YES";
            return 0;
        }
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(st[a][b]==2)
                continue;
            if (a < 1 || b < 1 || a > n || b > m)
                continue;
            if (s[a][b] == '#')
                continue;
            q.push({a, b});
            st[a][b] = 2;
        }
    }
    cout << "NO";

    return 0;
}