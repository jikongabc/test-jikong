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
const int N = 3e5 + 10;
LL a[N];
LL res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    s += "+";
    int n = s.size();
    int m = 0;
    int tmp = 0;
    for (int i = 0; i < n;i++){
        if(s[i]<='9' && s[i]>='0'){
            tmp *= 10;
            tmp += s[i] - '0';
        }
        else{
            a[m++] = tmp;
            res += a[m - 1];
            tmp = 0;
        }
    }
    sort(a, a + m);
    reverse(a, a + m);
    for (int i = 0; i < m-1;i++)
        cout << a[i] << '+';
    cout << a[m - 1];
    cout << endl;
    cout << res;
    return 0;
}
