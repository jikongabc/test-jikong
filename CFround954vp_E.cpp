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
LL res;

void solve(){
    res = 0;
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> ma;
    for (int i = 0; i < n;i++){
        int a;
        cin >> a;
        ma[a % k].push_back(a);
    }
    int cnt = 0;
    for (auto [_, a] : ma)
    {
        sort(a.begin(), a.end());
        if(a.size()%2==0){
            for (int i = 0; i < a.size();i+=2)
                res += (a[i + 1] - a[i]) / k;
        }
        else{
            cnt++;
            LL sum1 = 0;
            LL sum2 = 0;
            for (int i = 1; i < a.size();i+=2){
                sum1 += (a[i + 1] - a[i]) / k;
            }
            sum2 = sum1;
            // for (int i = 0; i < a.size() - 1;i+=2){
            //     sum2 += (a[i + 1] - a[i]) / k;
            // }
            for (int i = 0; i + 1 < a.size(); i += 2)
            {
                sum1 += (a[i + 1] - a[i]) / k;
                sum1 -= (a[i + 2] - a[i + 1]) / k;
                sum2 = min(sum2, sum1);
            }
            res += sum2;
        }
    }
    if(cnt>1)
        res = -1;
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}