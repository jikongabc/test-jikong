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
const int N = 12, M = 1 << 10, K = 110;

int n, m;
LL dp[N][K][M];
int cnt[M];
vector<int> st;//合法状态
vector<int> state[M];//可以转移的相邻状态

//判断是否有相邻的1
bool pd(int state){
    return !(state & state >> 1);
}

//统计状态中1的数量
int count(int state){
    int res = 0;
    for (int i = 0; i < n;i++)
        res += state >> i & 1;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < 1 << n;i++){
        if(pd(i)){
            st.push_back(i);
            cnt[i] = count(i);
        }
    }
    for (int i = 0; i < st.size();i++){
        for (int j = 0; j < st.size();j++){
            int a=st[i],b=st[j];
            if(!(a&b) && pd(a|b))
                state[a].push_back(b);
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n + 1;i++){
        for (int j = 0; j <= m;j++){
            for(auto a:st){
                for(auto b:state[a]){
                    if(j>=cnt[a])
                        dp[i][j][a] += dp[i-1][j - cnt[a]][b];
                }
            }
        }
    }
    cout << dp[n + 1][m][0];
    return 0;
}