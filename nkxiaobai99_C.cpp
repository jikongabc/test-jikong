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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
const int N = 1e3 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
int x, y, x1, y1;
char p[N][N];
bool st[N][N][2];

bool pd(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool bfs(){
    queue<PIII> q;
    q.push({{x, y}, 0});
    st[x][y][0] = 1;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first.first + dx[i], b = t.first.second + dy[i];
            if(pd(a,b) &&p[a][b]!='#' && !st[a][b][t.second]){
                st[a][b][t.second] = 1;
                if(a==x1 && b==y1)
                    return true;
                q.push({{a, b}, t.second});
            }    
        }
        if(!t.second){
            for (int i = 0; i < 4;i++){
                int a = t.first.first, b = t.first.second;
                bool flag = false;
                while(pd(a,b) && p[a][b]!='#'){
                    if(!st[a][b][1]){
                        st[a][b][1] = 1;
                        q.push({{a, b}, 1});
                    }
                    if (a == x1 && b == y1)
                        flag = true;
                    a += dx[i], b += dy[i];
                }
                if(flag)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> p[i][j];
            if(p[i][j]=='S')
                x = i, y = j;
            if(p[i][j]=='E')
                x1 = i, y1 = j;
        }
    }
    if(bfs())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
