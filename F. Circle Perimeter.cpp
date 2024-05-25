#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
LL T, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        LL ans = 0, j = n;
        for (LL i = 0; i <= n;i++){
            while(i*i+j*j>=(n+1)*(n+1))
                j--;
            LL temp = j;
            while(i*i+temp*temp>=n*n && temp>0){
                temp--;
                ans++;
            }
        }
        cout << ans * 4 << '\n';
    }
    return 0;
}
