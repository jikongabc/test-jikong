#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 100 + 10;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
const string op = "LRDU";
int n;
string s;
map<char, int> ma;
set<PII> se;
int st[N][N];

void dfs(int u,int x,int y){
    if(u==n){
        se.insert({x, y});
        return;
    }
    int xx = x + dx[ma[s[u]]], yy = y + dy[ma[s[u]]];
    if(st[xx+50][yy+50]==0){
        st[xx+50][yy+50] = 1;
        dfs(u + 1, xx, yy);
        st[xx + 50][yy + 50] = 2;
        dfs(u + 1, x, y);
        st[xx + 50][yy + 50] = 0;
    }
    if(st[xx+50][yy+50]==1)
        dfs(u + 1, xx, yy);
    if(st[xx+50][yy+50]==2)
        dfs(u + 1, x, y);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < 4;i++){
        ma[op[i]] = i;
    }
    st[50][50] = 1;
    dfs(0, 0, 0);
    // cout << endl;
    cout << se.size() << endl;
    for(auto i:se){
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}