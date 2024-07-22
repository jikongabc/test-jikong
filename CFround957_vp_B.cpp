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
const int N = 1e5 + 10;
int m, n;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int sum = 0;
        int sum1 = 0;
        cin >> m >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            sum += a[i];
            sum1 += a[i] - 1;
        }
        sort(a + 1, a + 1 + n);
        int res = sum - a[n] + sum1 - a[n] + 1;
        cout << res << endl;
    }

    return 0;
}