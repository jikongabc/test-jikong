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
void solve()
{
    string s, t;
    cin >> s >> t;
    int s_len = s.size();
    int t_len = t.size();

    int i = 0, j = 0;
    while (i < s_len && j < t_len)
    {
        if (s[i] == '?' || s[i] == t[j])
        {
            s[i] = t[j];
            j++;
        }
        i++;
    }

    if (j < t_len)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (int k = 0; k < s_len; k++)
        {
            if (s[k] == '?')
            {
                s[k] = 'a'; 
            }
        }
        cout << "YES" << endl;
        cout << s << endl;
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
