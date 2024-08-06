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
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int res = 0;

        int cnt1 = 0;
        int cnt2 = 0;
        if (a1 > b1)
            cnt1++;
        if(a1<b1)
            cnt2++;
        if (a2 > b2)
            cnt1++;
        if(a2<b2)
            cnt2++;
        if (cnt1 > cnt2)
            res++;

        cnt1 = 0;
        cnt2 = 0;
        if (a1 > b2)
            cnt1++;
        if (a1 < b2)
            cnt2++;
        if (a2 > b1)
            cnt1++;
        if (a2 < b1)
            cnt2++;
        if (cnt1 > cnt2)
            res++;

        cnt1 = 0;
        cnt2 = 0;
        if (a2 > b1)
            cnt1++;
        if (a2 < b1)
            cnt2++;
        if (a1 > b2)
            cnt1++;
        if (a1 < b2)
            cnt2++;
        if (cnt1>cnt2)
            res++;

        cnt1 = 0;
        cnt2 = 0;
        if (a2 > b2)
            cnt1++;
        if (a2 < b2)
            cnt2++;
        if (a1 > b1)
            cnt1++;
        if (a1 < b1)
            cnt2++;
        if (cnt1 > cnt2)
            res++;

        cout << res << endl;
    }

    return 0;
}
