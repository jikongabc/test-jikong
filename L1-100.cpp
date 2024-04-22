#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 505;
int n, m;
int a[N];
int sum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum - n * (m - 1)<0)
        cout << 0;
    else
        cout << sum - n * (m - 1);
    return 0;
}
