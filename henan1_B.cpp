#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
using PII = pair<int, int>;

int solve(int n)
{
    if (n == 0)
        return 0;

    queue<PII> q;
    unordered_set<int> se;

    q.push({0, 0});
    se.insert(0);

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == n)
        {
            return y;
        }

        int a = x + 1;
        int b = x + 2;
        int c = x * 2;

        if (a <= n && se.find(a) == se.end())
        {
            q.push({a, y + 1});
            se.insert(a);
        }
        if (b <= n && se.find(b) == se.end())
        {
            q.push({b, y + 1});
            se.insert(b);
        }
        if (c <= n && se.find(c) == se.end())
        {
            q.push({c, y + 1});
            se.insert(c);
        }
    }

    return -1; 

int main()
{
    int n;
    cin >> n;

    int res = solve(n);
    cout << res << endl;

    return 0;
}