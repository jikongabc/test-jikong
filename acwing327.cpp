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
const int N = 14, M = 1 << 12;
const int mod = 1e8;
int n, m;
int p[M];
vector<int> state;
vector<int> head[M];
int dp[N][M];

bool pd(int state){
    return !(state & state >> 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < m;j++){
            int t;
            cin >> t;
            p[i] += (!t) * 1 << j;
        }
    }
    for (int i = 0; i < 1 << m;i++){
        if(pd(i))
            state.push_back(i);
    }
    for (int i = 0; i < state.size();i++){
        for (int j = 0; j < state.size();j++){
            int a = state[i], b = state[j];
            if((a&b)==0)
                head[a].push_back(b);
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n + 1;i++){
        for(auto a:state){
            if((a&p[i])==0){
                for (auto b : head[a]){
                    dp[i][a] = (dp[i][a] + dp[i - 1][b]) % mod;
                }
            }
        }
    }
    cout << dp[n + 1][0];
    return 0;
}