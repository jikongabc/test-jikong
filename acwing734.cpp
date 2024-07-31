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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e4 + 10;
int n;
int dp[N];

struct Stone{
    int s, e, l;
} stone[N];

bool cmp(Stone a,Stone b){
    return a.s * b.l < b.s * a.l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    int C = 0;
    while(T--){
        C++;
        cin >> n;
        int m = 0;
        for (int i = 0; i < n;i++){
            int s, e, l;
            cin >> s >> e >> l;
            stone[i] = {s, e, l};
            m += s;
        }
        sort(stone, stone + n, cmp);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n;i++){
            int e = stone[i].e, s = stone[i].s, l = stone[i].l;
            for (int j = m; j >= s;j--){
                dp[j] = max(dp[j], dp[j - s] + max(0, e - l * (j - s)));
            }
        }
        int res = 0;
        for (int i = 0; i <= m;i++){
            res = max(res, dp[i]);
        }
        cout << "Case #" << C << ": " << res << endl;
    }
    return 0;
}