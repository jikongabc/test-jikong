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
string s;

void solve(){
    cin >> n;
    cin >> s;
    if(n==2){
        if(s[0]=='0')
            cout << s[1] << endl;
        else
            cout << s << endl;
        return;
    }
    int res = inf;
    for (int i = 0; i < n - 1;i++){
        int sum = 0;
        for (int j = 0; j < n;j++){
            int t = s[j] - '0';
            if(j==i){
                t = t * 10 + s[j + 1] - '0';
                j++;
            }
            if(t==0){
                cout << 0 << endl;
                return;
            }
            if(t!=1)
                sum += t;
        }
        res = min(res, sum);
    }
    cout << max(res, 1) << endl;
}

int main()
{
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