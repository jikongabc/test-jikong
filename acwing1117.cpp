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
const int N = 25;
string s[N];
int st[N][N];
int cnt[N];
int n;
int ans;
void dfs(string dragon ,int x){
    ans = max(ans, (int)dragon.size());
    cnt[x]++;
    for (int i = 0; i < n;i++){
        if(st[x][i] && cnt[i]<2){
            dfs(dragon + s[i].substr(st[x][i]), i);
        }
    }
    cnt[x]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> s[i];
    }
    char start;
    cin >>start;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            string a = s[i], b = s[j];
            for (int k = 1; k < min(a.size(), b.size());k++){
                if(a.substr(a.size()-k,k)==b.substr(0,k)){
                    st[i][j] = k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n;i++){
        if(s[i][0]==start)
            dfs(s[i], i);
    }
    cout << ans;
    return 0;

}