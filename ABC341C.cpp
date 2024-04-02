#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 505;
typedef pair<int, int> PII;
int n, m, l;
char ch[N][N];
string s;
queue<PII> q;
int cnt = 0;
bool judge(int x,int y){
    for (int i = 0; i < l;i++){
        if(s[i]=='L' && y>1)
            y--;
        else if(s[i]=='R' && y<m)
            y++;
        else  if(s[i]=='U' && x>1)
            x--;
        else if (s[i] == 'D' && x<n)
            x++;
        if(ch[x][y]!='.')
            return false;
    }
    return true;
}

int solve(){
    while (!q.empty()){
        auto t = q.front();
        q.pop();
        if(judge(t.first,t.second))
            cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> l;
    cin >> s;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> ch[i][j];
            if(ch[i][j]=='.'){
                q.push({i, j});
            }
        }
    }

    int ans = solve();
    cout << ans;
    return 0;
}