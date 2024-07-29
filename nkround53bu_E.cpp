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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;
int n;
int a[N];

bool check(int x)
{
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.emplace(a[i]);
    }
    for (int i = x; i >= 0; i--)
    {
        if (q.empty())
        {
            return false;
        }
        while (q.top() > i)
        {
            int t = q.top();
            q.pop();
            q.emplace(t / 2);
        }
        if (q.top() == i)
        {
            q.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 1e5 + 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l + 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}