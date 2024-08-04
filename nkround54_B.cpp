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
const int N = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL a, b, x;
    cin >> a >> b >> x;
    LL res1 = x * a;
    LL res2 = (x / 3) * b + (x % 3) * a;
    LL res = min(res1, res2);
    cout << res << endl;
    return 0;
}
