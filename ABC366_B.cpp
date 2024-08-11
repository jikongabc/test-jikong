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
    int n;
    cin >> n;

    vector<string> strings(n);
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
        m = max(m, (int)strings[i].size());
    }

    vector<string> res(m, string(n, '*'));

    for (int i = 0; i < n; i++)
    {
        int len = strings[i].size();
        for (int j = 0; j < len; j++)
        {
            res[j][n - i - 1] = strings[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int j = n - 1;
        while (j >= 0 && res[i][j] == '*')
            j--;
        cout << res[i].substr(0, j + 1) << endl;
    }

    return 0;
}
