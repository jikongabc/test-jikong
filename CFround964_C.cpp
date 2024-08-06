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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--){
        int n;
        LL s, m;
        cin >> n >> s >> m;

        vector<pair<LL, LL>> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i].first >> v[i].second;
        }

        bool flag = false;

        if (v[0].first >= s)
        {
            flag = true;
        }

        for (int i = 1; i < n; ++i)
        {
            if (v[i].first - v[i - 1].second >= s)
            {
                flag = true;
                break;
            }
        }

        if (m - v[n - 1].second >= s)
        {
            flag = true;
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
