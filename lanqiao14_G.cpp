#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<double, int> PDI;
const int N = 1005;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, k;
char ch[N][N];
bool st[N][N][15];
queue<PIIII> q;
int bfs(){
    int hh = 0, tt = 0;
    q.push({{0, 0}, {1, 0}});
    st[0][0][1] = 1;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int x = t.first.first + dx[i], y = t.first.second + dy[i];
            if(x<0 || y<0  || x>=n | y>=m)
                continue;
            if(t.second.first<k && ch[x][y]==ch[t.first.first][t.first.second]) {
                if(st[x][y][t.second.first+1])
                    continue;
                st[x][y][t.second.first + 1] = 1;
                q.push({{x, y}, {t.second.first + 1, t.second.second + 1}});
                // cout << x << ' ' << y << endl;
                if(x==n-1 && y==m-1)
                    return t.second.second + 1;
            }
            else if (t.second.first == k && ch[x][y] != ch[t.first.first][t.first.second]){
                if(st[x][y][1])
                    continue;
                st[x][y][1] = 1;
                q.push({{x, y}, {1, t.second.second + 1}});
                // cout << x << ' ' << y << endl;
                if (x == n - 1 && y == m - 1)
                    return t.second.second + 1;
            }
        }
        // cout << endl;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n;i++){
        cin >> ch[i];
    }
    if(n==1 && m==1){
        cout << 0;
        return 0;
    }
    cout << bfs();
    return 0;
}