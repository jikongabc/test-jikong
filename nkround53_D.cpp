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
int n, m, target;
int a[100][20];
int memo[101][5001];

int dfs(int index, int current_sum)
{
    if (index == n)
    {
        return abs(current_sum - target);
    }
    if (memo[index][current_sum] != -1)
    {
        return memo[index][current_sum];
    }

    int min_diff = 5000;
    for (int j = 0; j < m; ++j)
    {
        min_diff = min(min_diff, dfs(index + 1, current_sum + a[index][j]));
    }
    memo[index][current_sum] = min_diff;
    return min_diff;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    cin >> target;
    memset(memo, -1, sizeof(memo));
    int result = dfs(0, 0);

    cout << result << endl;

    return 0;
}
