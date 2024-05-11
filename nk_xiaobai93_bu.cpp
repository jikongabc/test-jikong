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
const int N = 2e5 + 10;
const int mod = 998244353;
int n;
string a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n;i++){
        if(a[i]>b[i])
            swap(a[i], b[i]);
    }
    LL temp1 = 0, temp2 = 0;
    for (int i = 0; i <n;i++){
        temp1 =(LL) (temp1 * 10 + (a[i] - '0')) % mod;
        temp2 = (LL)(temp2 * 10 + (b[i] - '0') % mod);
    }
    cout << temp1*temp2%mod;
    return 0;
}