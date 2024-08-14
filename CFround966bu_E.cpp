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
const int N = 2e5 + 10;
int n, m, k;
int w;

void solve(){
    cin >> n >> m >> k;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w;i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<vector<int>> d(n, vector<int>(m, 0));
    for (int i = 0; i <= n - k;i++){
        for (int j = 0; j <= m - k;j++){
            for (int x = i; x < i + k;x++){
                for (int y = j; y < j + k;y++){
                    d[x][y]++;
                }
            }
        }
    }
    priority_queue<int> q;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(d[i][j]>0)
                q.push(d[i][j]);
        }
    }
    LL res = 0;
    for (int i = 0; i < w && !q.empty();i++){
        LL t = q.top();
        q.pop();
        res += (LL)t * a[i];
    }
    cout << res << endl;
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
