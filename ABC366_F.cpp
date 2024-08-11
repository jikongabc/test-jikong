#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;
using LL = long long;

const int N = 10;
int a[N], b[N];
unordered_map<LL, LL> memo; // 用于记忆化搜索的哈希表
int n, k;
LL res = LLONG_MIN;

LL dfs(int depth, LL val)
{
    if (depth == k)
    {
        return val;
    }

    // 如果当前状态已经计算过，直接返回结果
    if (memo.count(val))
    {
        return memo[val];
    }

    LL max_val = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        LL next_val = a[i] * val + b[i];
        max_val = max(max_val, dfs(depth + 1, next_val));
    }

    // 记忆化当前状态的计算结果
    memo[val] = max_val;

    return max_val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    res = dfs(0, 1); // 从1开始，因为问题给出的初始值是1

    cout << res << endl;

    return 0;
}
