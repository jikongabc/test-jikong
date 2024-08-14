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
    while (T--)
    {
        string s;
        cin >> s;
        if(s[0]=='1' && s[1]=='0' && s[1]=='1' && s.size()==3){
            cout << "NO\n";
            continue;
        }
        if (s[0] == '1' && s[1] == '0' && s[2] != 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}