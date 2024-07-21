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
const int N = 1e5 + 10;
LL n;

LL ten(int x){
    return x == 0 ? 1 : ten(x - 1) * 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int d = 1;
    cin >> n;
    int x;
    if(n==1){
        cout << 0;
        return 0;
    }
    n--;
    while(1){
        x = (d + 1) / 2;
        if(n<=(LL)9*ten(x-1))
            break;
        n -=(LL) 9 * ten(x - 1);
        d++;
    }
    string res = to_string((LL)ten(x - 1) + n - 1);
    string t = res;
    // cout <<d<<' ' <<x << endl;

    reverse(t.begin(),t.end());
    if(d%2==0)
        res += t;
    else
        res += t.substr(1, res.size()-1);
    cout << res;
    return 0;
}
