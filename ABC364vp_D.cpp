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
const int N = 1e6 + 10;
int n, m;
int a[N];
int b[N], k[N];

int dis(int a,int b){
    return abs(a - b);
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m;i++){
        cin >> b[i] >> k[i];
        int x = lower_bound(a, a + n, b[i]) - a;
        int l = x - 1, r = x;
        vector<int> res;
        while(res.size()<k[i]){
            if(l>=0 &&(r>=n || dis(a[l],b[i])<=dis(a[r],b[i]))){
                res.push_back(dis(a[l], b[i]));
                l--;
            }
            else if(r<n){
                res.push_back(dis(a[r], b[i]));
                r++;
            }
        }
        cout << res[k[i] - 1] << endl;
    }
    return 0;
}