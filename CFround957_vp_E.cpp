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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        int res = 0;
        PII ans[N];
        string s = to_string(n);
        int len = s.size();
        int t = 0;
        for (int i = 1; i <= 10000;i++){
            int l = len * i - 6, r = len * i - 1;
            for (int j = max(l,1); j <= r;j++){
                string ss = "";
                for (int k = 0; k < (len*i-j)/len+1;k++){
                    ss += s;
                }
                if (ss.substr(0,len*i-j) == to_string(n * i - j))
                {
                    ans[t++] = {i, j};
                    res++;
                }
            }
        }
        cout << res << endl;
        for (int i = 0; i < t;i++){
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }
    return 0;
}