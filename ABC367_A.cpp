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
    int a, b, c;
    cin >> a >> b >> c;
    if(b>c)
        c += 24;
    if(a==0)
        a = 24;
    if(a>=b && a<=c)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}
