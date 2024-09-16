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
#include <bitset>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n;

void solve()
{
    cin >> n;
    bitset<N> dp;
    dp[0] = true;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        dp |= (dp << x);
        dp[x] = true;
    }
    for (int i = 1; i <= n;i++){
        if(!dp[i]){
            cout << i << endl;
            return;
        }
    }
    cout << "Cool!\n";
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