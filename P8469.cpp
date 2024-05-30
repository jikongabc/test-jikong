#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<double, int> PDI;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n;
int a[N];

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int res = inf;
    LL ans = 1;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        res = min(res, a[i]);
    }
    for (int i = 0; i < n;i++){
        ans *= (a[i] / res);
        ans %= mod;
    }
    cout << res << ' ' << ans % mod;
    return 0;

}