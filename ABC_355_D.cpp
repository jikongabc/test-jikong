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
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 5e5 + 10;
int n;
int l[N], r[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> l[i] >> r[i];
    }
    sort(l, l + n);
    sort(r, r + n);
    LL ans = n * (n - 1) / 2;
    for (int i = 0, j = 0; i < n;i++){
        while(r[j]<l[i])
            j++;
        ans -= j;
    }
    cout << ans;
    return 0;
}