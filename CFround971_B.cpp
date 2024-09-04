#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 5e2 + 10;

void solve()
{
    int n;
    cin >> n;
    string s[N];
    for (int i = 0; i < n;i++)
        cin >> s[i];
    for (int i = n - 1; ~i;i--){
        for (int j = 0; j < 4;j++){
            if (s[i][j] == '#'){
                cout << j + 1 << ' ';
                break;
            }
        }
    }
    cout << endl;
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