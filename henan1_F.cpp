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
const int N = 2e5 + 10;
const int mod = 998244353;
int n;
int a[N];

int _xor(const int a[])
{
    int res = 0;
    for (int i = 0; i < n;i++)
    {
        res ^= a[i];
    }
    return res;
}

int solve(int n)
{
    int res = _xor(a);
    int maxn = res;
    for (int i = 0; i < n; i++)
    {
        int maxnn = n / (i + 1);
        for (int j = 1; j <= maxnn; j++)
        {
            int t = a[i] + j;
            int num = (res ^ a[i]) ^ t;
            t = a[i] * j;
            int num1 = (res ^ a[i]) ^ t;
            maxn = max({maxn, num, num1});
        }
    }
    return maxn;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << solve(n) << endl;
    // cout << (1 ^ 2 ^ 3 ^ 4) << endl;
    // cout << (1 ^ 2 ^ 3) << endl;
    // cout << (1 ^ 2 ^ 3 ^ 4 ^ 4) << endl;
    // cout << (1 ^ 2 ^ 4) << endl;
    // cout << (1 ^ 2 ^ 3 ^ 3 ^ 4) << endl;
    return 0;
}


