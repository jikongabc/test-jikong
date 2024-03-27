#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
using LL = long long;
void solve()
{
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int i = 1; i <= d * c / b; i++)
    {
        LL num1 = a * c * i;
        LL num2 = (d * c - b * i);
        double x = num1 * 1.0 / num2 * 1.0;
        if (double(LL(x)) == x)
            ans++;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}