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
const int N = 1005;
int a[N];
int b[N][N];
int ans[N];
int temp[N];
int n, m;
int minn = 0x3f3f3f3f;

bool pd(int x){
    for (int i = 1; i <= n;i++){
        int sum = 0;
        for (int j = 1; j <= x;j++){
            sum += b[temp[j]][i];
        }
        if (sum < a[i])
            return false;
    }
    return true;
}

void dfs(int x,int cnt){
    if(x>m){
        if(pd(cnt)){
            if(cnt<minn){
                minn = cnt;
                for (int i = 1; i <= minn; i++){
                    ans[i] = temp[i];
                }
            }
        }
        return;
    }
    temp[cnt+1] = x;
    dfs(x + 1, cnt+1);
    temp[cnt+1] = 0;
    dfs(x + 1, cnt);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            cin >> b[i][j];
        }
    }
    dfs(1, 0);
    cout << minn <<' ';
    for (int i = 1; i <= minn;i++){
        cout << ans[i]<<' ';
    }

        return 0;
}