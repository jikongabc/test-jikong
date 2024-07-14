#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 5e5 + 10;
int n;
int q;
int a[N];
LL b[N];

int l, r;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        sum += a[i];
    }
    cin >> q;
    LL res = 0;
    while(q--){
        cin >> l >> r;
        for (int i = l; i <= r;i++){
            for (int j = i; j <= r;j++){
                res = max(res, abs(b[j] - b[i]));
            }
        }
        cout << res << endl;
    }
    return 0;
}
