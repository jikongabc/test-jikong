#include <iostream>
// #include <algorithm>
#include <cstring>
// #include <cstdio>
#include <queue>
// #include <deque>
// #include <vector>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <string>
using namespace std;
#define int long long
// using LL = long long;
const int N = 1e6 + 10;
// int dx[] = {-1, 1};
int st[N];
int bfs(int x,int y){
    // int maxn = max(x, y);
    // int minn = min(x, y);
    memset(st, -1, sizeof st);
    queue<int> q;
    q.push(x);
    st[x] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if (t == y)
            return st[t];
        if(t-1>=0 && st[t-1]<0){
            q.push(t - 1);
            st[t - 1] = st[t] + 1;
        }
        if(t+1<=N && st[t+1]<0){
            q.push(t + 1);
            st[t + 1] = st[t] + 1;
        }
        if(t*2<=N && st[t*2]<0){
            q.push(t * 2);
            st[t * 2] = st[t] + 1;
        }
    }
    return -1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        int n, k;
        cin >> n >> k;
        int ans = bfs(n, k);
        cout << ans << endl;
    

    return 0;
}

