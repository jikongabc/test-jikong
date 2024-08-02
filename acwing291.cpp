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
const int N = 12, M = 1 << N;
int n, m;
bool st[M];
vector<int> state[M];
LL dp[N][M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m, n||m){
        for (int i = 0; i < 1 << n;i++){
            bool flag=true;
            int cnt = 0;
            for (int j = 0; j < n;j++){
                if(i>>j&1){
                    if(cnt&1){
                        flag = false;
                        break;
                    } 
                }
                else
                    cnt++;
            }
            if(cnt&1)
                flag = false;
            st[i] = flag;
        }
        for (int i = 0; i < 1 << n;i++){
            state[i].clear();
            for (int j = 0; j < 1 << n;j++){
                if((i&j)==0 && st[i|j])
                    state[i].push_back(j);
            }
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= m;i++){
            for (int j = 0; j < 1 << n;j++){
                for(auto k:state[j])
                    dp[i][j] += dp[i - 1][k];
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}