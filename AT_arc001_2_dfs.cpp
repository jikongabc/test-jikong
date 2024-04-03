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
const int N = 50;
int dx[] = {-1, 1, -5, 5, -10, 10};
int a, b;
int st[N];
int ans = 0x3f3f3f3f;
void dfs(int x,int cnt){
    if(cnt>=ans)
        return;
    if(x==b){
        ans = min(ans, cnt);
        return;
    }
    if(x>b){
        dfs(x - 1, cnt + 1);
        dfs(x - 5, cnt + 1);
        dfs(x - 10, cnt+ 1);
    }
    else{
        dfs(x + 1, cnt + 1);
        dfs(x + 5, cnt + 1);
        dfs(x + 10, cnt + 1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    dfs(a, 0);
    cout << ans;
    return 0;
} 