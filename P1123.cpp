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
const int N = 10;
int t;
int n, m;
int p[N][N];
bool st[N][N];
int ans;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x,int y,int sum){
    if(x==n){
        ans = max(ans, sum);
        return;
    }
    int a = x, b = y + 1;
    if(b==m){
        a++;
        b = 0;
    }
    if(!st[x-1][y] && !st[x][y-1] && !st[x-1][y-1] && !st[x+1][y] && !st[x][y+1] && !st[x+1][y+1] && !st[x+1][y-1] && !st[x-1][y+1]){
        st[x][y] = 1;
        dfs(a, b, sum+p[x][y]);
        st[x][y] = 0;
    }
    dfs(a, b, sum);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                cin >> p[i][j];
            }
        }
        dfs(0, 0, 0);
        cout << ans << endl;
    }

    return 0;
}
