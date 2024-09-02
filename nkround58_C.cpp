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
const int N = 1e5 + 10;
const int dx[] = {1, 0}, dy[] = {0, 1};
int dist[105][105];

// int bfs(int x,int y){
//     memset(dist, -1, sizeof dist);
//     dist[0][0] = 0;
//     PII q[N];
//     int hh = 0, tt = 0;
//     q[0] = {0, 0};
//     while(hh<=tt){
//         auto t = q[hh++];
//         for (int i = 0; i < 2;i++){
//             int a = t.first + dx[i], b = t.second + dy[i];
//             if(dist[a][b]==-1){
//                 dist[a][b] = dist[t.first][t.second] + 1;
//                 q[++tt] = {a, b};
//                 if (a == x && b == y)
//                     return dist[a][b];
//             }
//         }
//     }
// }

void solve(){
    int x, y;
    cin >> x >> y;
    if(x<0 || y<0){
        cout << "PING\n";
        return;
    }
    // if(bfs(x,y) & 1)
    //     cout << "YES\n";
    // else
    //     cout << "NO\n";
    if(x==y){
        cout << "NO\n";
        return;
    }
    // if(x==0 && y==1 || x==1 && y==0){
    //     cout << "YES\n";
    //     return;
    // }
    // else{
    //     cout << "PING\n";
    //     return;
    // }
    if(x-y==1 || y-x==1){
        cout << "YES\n";
        return;
    }
    else
        cout << "PING\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}