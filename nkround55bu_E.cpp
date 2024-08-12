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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n;
int a[N];
LL cnt[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    LL res = 0;
    for (int i = 0; i < n; i++){
        int digit = a[i] % 10;
        LL newcnt[10];
        for (int j = 0; j < 10; j++){
            newcnt[j] = cnt[j];
        }
        newcnt[digit] = (newcnt[digit] + 1) % mod;

        for (int j = 0; j < 10; j++){
            newcnt[(j * digit) % 10] = (newcnt[(j * digit) % 10] + cnt[j]) % mod;
        }

        for (int j = 0; j < 10; j++){
            cnt[j] = newcnt[j];
        }
        res = (res + cnt[6]) % mod;
    }
    cout << res;

    return 0;
}
