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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n, m;

int dfs(int l,int r,int sum){
    if(sum==0)
        return 1;
    int t = 0;
    if(sum&1){
        for (int i = 1; r - i > l;i++){
            t = (t + dfs(l, r - i, sum - 1)) % mod;
        }
    }
    else{
        for (int i = 1; l + i < r;i++){
            t = (t + dfs(l + i, r, sum - 1)) % mod;
        }
    }
    return t % mod;
}

void solve()
{
    cin >> n >> m;
    if(m==1){
        cout << 1 << endl;
        return;
    }
    // if(n-m==1){
    //     cout << 1 << endl;
    //     return;
    // }
    else{
        cout << dfs(1, n, m - 1) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}