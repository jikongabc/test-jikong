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
const int N = 1e4 + 10;
int n, op;
string id;
map<string, set<string>> ma;

// bool pd(string x, string y)
// {
//     if (x.size() > y.size())
//         return false;
//     for (int i = 0; i < x.size();i++){
//         if(x[x.size()-i-1]!=y[y.size()-i-1])
//             return false;
//     }
//     return true;
// }

bool pd(const string &x, const string &y)
{
    if (x.size() > y.size())
        return false;
    return equal(x.rbegin(), x.rend(), y.rbegin());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> id >> op;
        for (int j = 0; j < op; ++j)
        {
            string ss;
            cin >> ss;
            ma[id].insert(ss);
        }
    }

    for (auto i : ma)
    {
        set<string> se;
        for (auto j : i.second)
        {
            bool flag = true;
            for (auto k : i.second)
            {
                if (j != k && pd(j, k))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                se.insert(j);
            }
        }
        i.second = se;
    }
    cout << ma.size() << endl;
    for (auto i : ma)
    {
        cout << i.first << ' ' << i.second.size();
        for (auto j : i.second)
        {
            cout << ' ' << j;
        }
        cout << endl;
    }
    return 0;
}

