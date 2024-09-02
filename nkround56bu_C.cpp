#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;

int lowbit(int n){
    return n & -n;
}

void solve(){
    cin >> n;
    if(n==1)
        cout << 2 << ' ' << 3 << endl;
    else if(n==1e9)
        cout << lowbit(n) << ' ' << (n ^ lowbit(n)) << endl;
    else
        cout << 1 << ' ' << (n ^ 1) << endl;
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