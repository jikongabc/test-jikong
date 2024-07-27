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
int n;
int a[N];
int q[N];
int h[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>a[n])
        n++;
    int res = 0;
    for (int i = 0; i < n;i++){
        int l = 0, r = res;
        while(l<r){
            int mid = l + r + 1 >> 1;
            if(q[mid]>=a[i])
                l = mid;
            else
                r = mid - 1;
        }
        res = max(res, r + 1);
        q[r + 1] = a[i];
    }
    cout << res << endl;
    int cnt = 0;
    for (int i = 0; i < n;i++){
        int k = 0;
        while(k<cnt && h[k]<a[i])
            k++;
        if(k==cnt)
            h[cnt++] = a[i];
        else
            h[k] = a[i];
    }
    cout << cnt;
    return 0;
}