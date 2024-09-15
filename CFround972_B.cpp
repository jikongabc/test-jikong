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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
string s = "aeiou";
int n, m, q;
int b[N];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m;i++)
        cin >> b[i];
    sort(b, b + m);
    while(q--){
        int x;
        cin >> x;
        if(x==b[0] || x==b[1])
            cout << 0 << endl;
        else if(x>b[0] && x<b[1]){
            int t = (b[0] + b[1]) / 2;
            cout << min(abs(b[0] - t), abs(b[1] - t)) << endl;
        }
        else if(x<b[0]  && x>=1){
            cout << b[0] - 1 << endl;
        }
        else if(x>b[1] && x<=n)
            cout << n - b[1] << endl;
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