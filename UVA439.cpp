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
const int N = 10;
char ch1, ch2;
int x1, y1, x2, y2;
int p[N][N];
int st[N][N];
int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
queue<PII> q;
int bfs(){
    memset(st, -1, sizeof st);
    q.push({x1, y1});
    st[x1][y1] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(x1==x2 && y1==y2)
            return 0;
        for (int i = 0; i < 8;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<=0 || b<=0 || a>8 || b>8)
                continue;
            if(st[a][b]>=0)
                continue;
            st[a][b] = st[t.first][t.second] + 1;
            q.push({a, b});
            if (a == x2 && b == y2){
                return st[a][b];
            }
        }
    }
    return -1;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    while(cin >> ch1 >> y1 >> ch2 >> y2){
        while(!q.empty()){
            q.pop();
        }
        x1 = ch1 - 'a' + 1, x2 = ch2 - 'a' + 1;
        int ans = bfs();
        printf("To get from %c%d to %c%d takes %d knight moves.\n", ch1, y1, ch2, y2, ans);
    }
    return 0;
}