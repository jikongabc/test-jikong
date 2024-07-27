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
const int N = 2e5 + 10;
int n;
PII a[N];
int q[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);
    int res = 0;
    for (int i = 1; i <= n; i++){
        int l = 0, r = res;
        while(l<r){
            int mid = l + r + 1 >> 1;
            if(q[mid]<a[i].second)
                l = mid;
            else
                r = mid - 1;
        }
        res = max(res, r + 1);
        q[r + 1] = a[i].second;
    }
    cout << res;
    return 0;   
}