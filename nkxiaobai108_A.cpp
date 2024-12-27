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
// const int N =  ;


void solve(){
    LL x, y;
    cin >> x >> y;
    LL n;
    if(y <= 0){
        n = 0;
    }
    else if(x == 0){
        n = 2 * y - 1;
    }
    else{
        LL ceil1 = (y + x) / (x + 1);
        LL ceil2 = (y - 1 + x) / (x + 1);
        LL n1 = 2 * ceil1;
        LL n2 = 2 * ceil2 + 1;
        n = min(n1, n2);
    }
    cout << n << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
