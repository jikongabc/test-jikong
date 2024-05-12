// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     map<string, int> ma;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         string s;
//         int num;
//         cin >> s;
//         cin >> num;
//         ma[s] = num;
//     }
//     int p;
//     cin >> p;
//     while (p--)
//     {
//         string s;
//         cin >> s;
//         ma[s]--;
//     }
//     int ans = 0;
//     for (auto a : ma)
//     {
//         if (a.second <= 0)
//             ans++;
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 105;
int a[N], b[N], minn = inf;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        minn = min(minn, b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "WinWinWin!!!";
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > minn)
        {
            cout << "HaHa";
            return 0;
        }
    }
    cout << "AreYouOK?";

    return 0;
}
