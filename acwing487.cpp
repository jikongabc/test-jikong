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
const int N = 65, M = 32100;
int n, m;
int dp[M];
PII master[N];
vector<PII>son[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n;i++){
        int v, p, q;
        cin >> v >> p >> q;
        p *= v;
        if(!q)
            master[i] = {v, p};
        else{
            son[q].push_back({v, p});
        }
    }
    for (int i = 1; i <= n;i++){
        int v = master[i].first, w = master[i].second;
        for (int j = m; j >= 0;j--){
            for (int k = 0; k < 1 << son[i].size();k++){
                for (int u = 0; u < son[i].size();u++){ 
                    if(k >> u & 1){
                        v += son[i][u].first;
                        w += son[i][u].second;
                    }
                }
                if (j >= v)
                    dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    cout << dp[m];
    return 0;
}