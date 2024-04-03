#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1005;
bool st[N][N];
char ch[N][N];
int n, m, ans;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool judge(int x,int y){
    int cnt = 0;
    if(ch[x][y]=='#')
        cnt++;
    if(ch[x+1][y]=='#')
        cnt++;
    if(ch[x][y+1]=='#')
        cnt++;
    if(ch[x+1][y+1]=='#')
        cnt++;
    if(cnt==3)
        return false;
    return true;
}

void dfs(int x,int y){
    st[x][y] = 1;
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=m)
            continue;
        if(st[a][b])
            continue;
        if(ch[a][b]!='#')
            continue;
        st[a][b] = 1;
        dfs(a, b);
    }
}

int main(){
    // ios::sync_with_stdio(0);cin.tie(0);
    // cout.tie(0);
    bool temp = 1;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> ch[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if (!judge(i, j)){
                cout << "Bad placement.";
                temp = 0;
                return 0;
            }
            if (ch[i][j] == '#'){
                if(!st[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        
        }
    }
    if(temp)
        printf("There are %d ships.", ans);
        // cout << " There are" << ' ' << ans << ' ' << "ships.";
    return 0;
}