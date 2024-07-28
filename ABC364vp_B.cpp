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
const int N = 105;
const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

char p[N][N];
int x, y;
string s;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> x >> y;
    for (int i = 1; i <=n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
        }
    }
    cin >> s;
    for (int i = 0; i < s.size();i++){
        int a, b;
        if(s[i]=='L')
            a = x, b = y - 1;
        else if(s[i]=='R')
            a = x, b = y + 1;
        else if(s[i]=='U')
            a = x - 1, b = y;
        else if(s[i]=='D')
            a = x + 1, b = y;
        if(a<=0 || b<=0 || a>n ||  b>m)
            continue;
        if(p[a][b]=='#')
            continue;
        x = a, y = b;
    }
    cout << x << ' ' << y;
    return 0;
}