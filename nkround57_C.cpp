#include <iostream>
#include <cmath>

using namespace std;
using LL = long long;

// 判断n在k进制下是否是好数
bool pd(LL n, LL k)
{
    while (n > 0)
    {
        if (n % k > 1)
        {
            return false;
        }
        n /= k;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL n;
    cin >> n;

    for (LL i = 2; i <= n; i++)
    { // 遍历k1
        if (pd(n, i))
        {
            for (LL j = i + 1; j <= n; j++)
            { // 遍历k2
                if (pd(n, j))
                {
                    cout << "YES" << endl;
                    cout << i << ' ' << j << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
