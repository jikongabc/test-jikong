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
int a, b, c;
int x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int res = inf;
        cin >> a >> b >> c;
        if(a>b)
            swap(a, b);
        if(a>c)
            swap(a, c);
        if(b>c)
            swap(b, c);
        for (int i = a; i <= c;i++){
            res = min(res, abs(a - i) + abs(b - i) + abs(c - i));
        }
        cout << res << endl;
    }
    return 0;
}