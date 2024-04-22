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
map<int, int> ma;
int a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    int res = 0;
    for (int i = a; i <= b; i++)
    {
        int temp = i;
        int cnt = 0;
        while (temp > 9)
        {
            int sum = 1;
            while (temp != 0)
            {
                int num = temp % 10;
                temp /= 10;
                sum *= num;
            }
            temp = sum;
            cnt++;
        }
        ma[i] = cnt;
        res = max(res, cnt);
    }
    cout << res << "\n";
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (ma[i] == res)
        {
            if(count)
                cout << ' ' << i;
            else cout << i;
            count++;
        }
        // if (ma[i + 1] == res && count > 0)
        //     cout << '&';
    }
    return 0;
}