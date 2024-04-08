#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 25;
int n, m, p, q;
int minn;
int a[N][N], s[N];
int ans;
int l, r;
void dfs(int x,int y){
    if(y>s[x]){
        minn = min(minn, max(l, r));
        return;
    }
    l += a[x][y];
    dfs(x, y + 1);
    l -= a[x][y];
    r += a[x][y];
    dfs(x, y + 1);
    r -= a[x][y];
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < s[i];j++){
            minn = 0x3f3f3f;
            cin >> a[i][j];
        }
        dfs(i, 0);
        ans += minn;
    }
    cout << ans;

    return 0;
}