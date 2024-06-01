#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 1e6 + 10;
int n, k;
int a[N];
unordered_map<int, int> ma;
bool st[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n ;i++){
        cin >> a[i];
    }
    for (int i=1; i <= n;i++){
        if (i - ma[a[i]] <= k && ma[a[i]]!=0)
            st[a[i]] = 1;
            ma[a[i]] = i;
    }
    int res = 0;
    for (int i = 0; i < N;i++){
        if(st[i])
            res ^= i;
    }
    cout << res;
    return 0;
}