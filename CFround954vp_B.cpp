#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 105;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
LL a[N][N];
int n, m;

void pd(){
    bool flag = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            bool flag1 = 1;
            LL maxn = 0;
            for (int k = 0; k < 4;k++){
                int x = i + dx[k], y = j + dy[k];
                if(x<=0 || y<=0 || x>n || y>m)
                    continue;
                if(a[x][y]>=a[i][j]){
                    flag1 = 0;
                    break;
                }
                maxn = max(maxn, a[x][y]);
            }
            if (flag1){
                a[i][j] = maxn;
                flag = 0;
            }
            // if (!flag)
            //     break;
        }
        // if(!flag)
        //     break;
    }
    // if(!flag)
    //     pd();
    // return;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    pd();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    // cout << endl;
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