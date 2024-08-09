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
const int N = 70;
int n;
int len;
int w[N];
bool st[N];
int sum;

bool dfs(int u, int s, int start)
{
    if (u * len == sum)
        return true;
    if (s == len)
        return dfs(u + 1, 0, 0);
    for (int i = start; i < n; i++)
    {
        if (st[i] || s + w[i] > len)
            continue;
        st[i] = 1;
        if (dfs(u, s + w[i], i + 1))
            return true;
        st[i] = 0;
        if (!s || s + w[i] == len)
            return false;
        int j = i;
        while (w[j] == w[i] && j < n)
            j++;
        i = j - 1;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    sort(w, w + n,greater<int>());
    // reverse(w, w + n);
    len = w[0];
    while (1)
    {
        if (sum % len == 0 && dfs(0, 0, 0))
        {
            cout << len << endl;
            break;
        }
        len++;
    }
    return 0;
}