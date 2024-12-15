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
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
const int N = 1e5 + 10;
int n, x, y;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    cin >> s;
    vector<int> nxt1(n+2, n+1); //下一个相同
    vector<int> nxt2(n+2, n+1); //下一个不同
    int last0 = n + 1, last1 = n + 1;
    for(int i = n; i >= 1; i--){
        if(s[i-1] == '0'){
            nxt1[i] = last0;
            nxt2[i] = last1;
            last0 = i;
        }
        else{
            nxt1[i] = last1;
            nxt2[i] = last0;
            last1 = i;
        }
    }

    vector<LL> dp(n + 2, lnf);
    dp[1] = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] == lnf) continue;
        if(nxt1[i] <= n){
            dp[nxt1[i]] = min(dp[nxt1[i]], dp[i] + x);
        }
        if(nxt2[i] <= n){
            dp[nxt2[i]] = min(dp[nxt2[i]], dp[i] + y);
        }
    }
    if(dp[n] == lnf){
        cout << -1 << endl;
    }
    else{
        cout << dp[n] << endl;
    }
    return 0;
}
