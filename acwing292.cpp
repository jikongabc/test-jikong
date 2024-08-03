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
const int N = 110, M = 1 << 10;
int n, m;
int g[N];
int cnt[M];
int dp[2][M][M];
vector<int> state;
vector<int> head[M];

bool pd(int state){
    return !(state & state >> 1 || state & state >> 2);
}

int count(int state){
    int res = 0;
    for (int i = 0; i < m;i++)
        res += state >> i & 1;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < m;j++){
            char t;
            cin >> t;
            if(t=='H')
                g[i] += (1 << j);
        }
    }
    for (int i = 0; i < 1 << m;i++){
        if(pd(i)){
            state.push_back(i);
            cnt[i] = count(i);
        }
            
    }
    for(auto a:state){
        for(auto b:state){
            if(!(a&b))
                head[a].push_back(b);
        }
    }
    for (int i = 1; i <= n + 2;i++){
        for(auto a:state){
            for(auto b:head[a]){
                for(auto c:head[b]){
                    if(g[i]&a || g[i-1]&b)
                        continue;
                    if(a&b || b&c ||a&c)
                        continue;
                    dp[i & 1][a][b] = max(dp[i & 1][a][b], dp[i - 1 & 1][b][c] + cnt[a]);
                }
            }
        }
    }
    cout << dp[n + 2 & 1][0][0];
    return 0;
}