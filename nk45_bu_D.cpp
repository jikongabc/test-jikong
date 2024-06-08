#include <iostream>
#include <sstream>
#include <vector>
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
const int N = 1e5 + 10;
int n, k;
int a[N];
map<int, int> ma;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    LL res = 0;
    for (int l = 1, r = 0; l <= n; l++){
        // r = l;
        while(r<n && (r+1-ma[a[r+1]]<=k || ma[a[r+1]]==0)){
            r++;
            ma[a[r]] = r;
        }
        if(ma[a[l]]==l)
            ma[a[l]] = 0;
        res += r - l + 1;
    }
    cout << res;
    return 0;
}