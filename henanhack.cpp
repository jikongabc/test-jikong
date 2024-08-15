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
const int N = 1e5 + 10;
bool dp[2025][13][32];
// 闰年
bool pd(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

// 数一个月有几天
int count(int year, int month)
{
    if (month == 2)
    {
        if (pd(year))
            return 29;
        else
            return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

// //枚举2000.1.1 -> ... 有多少天
// LL get_step(int year,int month,int day){
//     LL res = 0;
//     for (int i = 2000; i < year;i++){
//         if(pd(i))
//             res += 366;
//         else
//             res += 365;
//     }
//     for (int i = 1; i < month;i++){
//         res += count(year, i);
//     }
//     res += day;
//     return res;
// }

void init()
{
    for (int i = 2024; i >= 2000; i--)
    {
        for (int j = 12; j >= 1; j--)
        {
            for (int k = count(i, j); k >= 1; k--)
            {
                if (i == 2024 && j == 8 && k == 1)
                    dp[i][j][k] = 0;
                else
                {
                    dp[i][j][k] = 0;
                    if (k < count(i, j))
                    {
                        if (!dp[i][j][k + 1])
                            dp[i][j][k] = 1;
                    }
                    else if (j < 12)
                    {
                        if (!dp[i][j + 1][1])
                            dp[i][j][k] = 1;
                    }
                    else if (!dp[i + 1][1][1])
                        dp[i][j][k] = 1;
                    if (j < 12 && k <= count(i, j + 1))
                    {
                        if (!dp[i][j + 1][k])
                            dp[i][j][k] = 1;
                    }
                    else if (j == 12 && k <= count(i + 1, j))
                    {
                        if (!dp[i + 1][1][k])
                            dp[i][j][k] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    T = 1;
    init();
    while (T--)
    {
        // int a, b, c;
        // cin >> a >> b >> c;
        // LL t1 = get_step(a, b, c);
        // LL t2 = get_step(2024, 8, 1);
        for (int i = 2024; i >= 2000; i--)
        {
            for (int j = 12; j >= 1; j--)
            {
                for (int k = count(i, j); k >= 1; k--)
                {
                    if (dp[i][j][k] && ((j+k)%2!=0))
                        cout << "YES---" << i << ' ' << j << ' ' << k << endl;
                 // else
                 //     cout << "NO---" << a << ' ' << b << ' ' << c << endl;
                }
            }
        }
        // if (dp[a][b][c])
        //     cout << "YES---" << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}
