#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 5e3 + 10;
int l, n;
int ans_max, ans_min;
int a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        ans_min = max(min(l + 1 - a[i], a[i]), ans_min);
        ans_max = max(max(l + 1 - a[i], a[i]), ans_max);
    }
    cout << ans_min << ' ' << ans_max;

    return 0;
}