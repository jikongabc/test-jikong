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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        for (int i = 0; i < 5; i++)
        {
            sort(a, a + 3);
            reverse(a, a + 3);
            a[2]++;
        }
        cout << a[0] * a[1] * a[2] << endl;
    }
    return 0;
}