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
#include <bitset>
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
const int N = 1e5 + 10;
int a, b, k;

void solve(){
    cin >> a >> b >> k;
    if ((a > 0 && b > 0 && (k < 1 || k > a + b - 1)) || ((a == 0 || b == 0) && k != 0))
    {
        cout << -1 << endl;
        return;
    }
    if (k == 0)
    {
        if (a > 0 && b > 0)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            cout << (a > 0 ? string(a, '0') : string(b, '1')) << endl;
        	return;
        }
    }
    char start = (a >= b) ? '0' : '1';
    // cout << start << endl;
    int cnt = k + 1;
    int cnt_start = (cnt + 1) / 2;
    int cnt_sstart = cnt / 2;
    int cnt0 = (start == '0') ? a : b;
    int cnt1 = (start == '0') ? b : a;
    // cout << "---" << cnt << ' ' << cnt_start << ' ' << cnt_sstart << ' ' << cnt0 << ' ' << cnt1 << endl;
    if (cnt0 < cnt_start || cnt1 < cnt_sstart)
    {
        cout << -1 << endl;
        return;
    }
    // a:基本字符 b:多余
    int a0 = cnt0 / cnt_start, b0 = cnt0 % cnt_start;
    int a1 = cnt1 / cnt_sstart, b1 = cnt1 % cnt_sstart;
    // cout << "---" << a0 << ' ' << b0 << ' ' << a1 << ' ' << b1 << endl;
    string s = "";
    for (int i = 0; i < cnt; i++)
    {
        if (i % 2 == 0)
        {
            int num = a0 + (b0 > 0 ? 1 : 0);
            s += string(num, start);
            if (b0 > 0)
                b0--;
        }
        // cout << "sss1:" << s << endl;
        else
        {
            char other = (start == '0') ? '1' : '0';
            int num = a1 + (b1 > 0 ? 1 : 0);
            s += string(num, other);
            if (b1 > 0)
                b1--;
        }
        // cout << "sss2:" << s << endl;
    }
    cout << s << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int T;
    cin >> T;
    // T = 1;
    while(T--){
        solve();
    }
    return 0;
}
