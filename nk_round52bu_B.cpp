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
const int N = 5e5 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        LL a, b, n;
        cin >> a >> b >> n;
        b = b / 2;
        //n-b*3>a
        if (n - min(b, n / 3) * 3 > a)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}