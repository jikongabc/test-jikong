#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
typedef pair<int, int> PII;
int n;
int a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        LL ans = 0;
        for (int x = 0; x < 3;x++){
            for (int y = x + 1; y < 3;y++){
                map<PII, int> cnt;
                for (int i = 0; i < n - 2;i++){
                    ans += cnt[{a[i + x], a[i + y]}]++;
                }
            }
        }
        map<tuple<int, int, int>, int> cnt;
        for (int i = 0; i < n - 2;i++){
            ans -= 3*cnt[{a[i], a[i + 1], a[i + 2]}]++;
        }
        cout << ans << endl;
    }
    return 0;
}