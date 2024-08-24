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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, k;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = n - k; i < n;i++)
        cout << a[i] << ' ';
    for (int i = 0; i < n - k;i++)
        cout << a[i] << ' ';
        return 0;
}
