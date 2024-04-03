#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 505;
int n, m;
bool judge;
char ch[N][N];
bool st[N][N];
int x1, y1, x2, y2;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x,int y){
    if(x==x2 && y==y2){
        judge = 1;
        cout << "Yes";
        return;
    }
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=m)
            continue;
        if(st[a][b])
            continue;
        if(ch[a][b]=='#')
            continue;
        st[a][b] = 1;
        dfs(a, b);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> ch[i][j];
            if(ch[i][j]=='s')
                x1 = i, y1 = j;
            if(ch[i][j]=='g')
                x2 = i, y2 = j;
        }
    }
    st[x1][y1] = 1;
    dfs(x1, y1);
    if(!judge)
        cout << "No";
    return 0;
}