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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n;
int a[N];
string s;
LL b[N];

void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    cin >> s;
    s = ' ' + s;
    int l = 1, r = n;
    LL res = 0;
    while(l<r){
        while(l<=r && s[l]!='L')
            l++;
        while(l<=r && s[r]!='R')
            r--;
        if(l<=r){
            res += b[r] - b[l - 1];
            l++;
            r--;
        }
            
        else
            break;
    }
    cout << res << endl;
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
