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
int n, k;

void solve()
{
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int size = n / k;

    vector<string> v(size, string(size, '0'));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            v[i][j] = a[i * k][j * k];
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << v[i] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
