#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<list>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 105;
char ch[N][N];
bool st[N][N];
int n, m;
int ans;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x,int y){
    st[x][y] = 1;
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=m)
            continue;
        if(st[a][b])
            continue;
        if(ch[a][b]=='0')
            continue;
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
        cin >> ch[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(!st[i][j] && ch[i][j]!='0'){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}