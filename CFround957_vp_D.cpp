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
const int N = 1e5 + 10;
int n, m, k;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        bool flag = 0;
        cin >> n >> m >> k;
        cin >> s;
        int x = -1;
        for (int i = 0; i <= n; i++)
        {
            if (x >= 0 && s[x] == 'W')
            {
                x++;
                k--;
            }
            else if (i == n || s[i] == 'L' || i - x == m)
            {
                x = i;
            }
            if (x >= 0 && x < n && s[x] == 'C')
            {
                cout << "NO\n";
                flag = 1;
                break;
            }
        }
        if (!flag){
            if (k >= 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}